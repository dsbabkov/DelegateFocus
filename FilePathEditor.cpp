#include "FilePathEditor.h"
#include "ui_FilePathEditor.h"
#include <QProcess>
#include <QDebug>
#include <QModelIndex>

FilePathEditor::FilePathEditor(QWidget *parent, const QModelIndex &modelIndex)
    : QWidget(parent)
    , ui(new Ui::FilePathEditor)
    , modelIndex_(modelIndex)
{
    ui->setupUi(this);
    const QString path = QDir::toNativeSeparators(modelIndex.data(Qt::EditRole).toString());
    setPath(path);
    setupDialog();
    connect(ui->editBtn, &QToolButton::clicked, this, &FilePathEditor::executeNotepad);
    setFocusProxy(ui->editBtn);
}

FilePathEditor::~FilePathEditor()
{
    delete ui;
}

void FilePathEditor::setPath(const QString &path) {
    ui->pathEdit->setText(QDir::toNativeSeparators(path));
}

QString FilePathEditor::path() const {
    return ui->pathEdit->text();
}

void FilePathEditor::setupDialog() {

    auto execDialog = [this] {
        setPath(QFileDialog::getOpenFileName(this, {}, path()));
    };

    connect(ui->browseBtn, &QToolButton::clicked, execDialog);
}

void FilePathEditor::executeNotepad() {
    QString program = "notepad";
    QStringList args {QDir::toNativeSeparators(path())};
#ifdef Q_OS_LINUX
    args.prepend(program);
    program = "wine";
#endif

    QProcess process;

    process.start(program, args);
    process.waitForFinished(-1);
}
