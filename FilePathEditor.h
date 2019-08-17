#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QModelIndex>

namespace Ui {
class FilePathEditor;
}

class QAbstractItemModel;

class FilePathEditor : public QWidget
{
    Q_OBJECT

public:
    explicit FilePathEditor(QWidget *parent, const QModelIndex &modelIndex);
    ~FilePathEditor() override;

    void setPath(const QString &path);
    QString path() const;

    void setupDialog();
    void executeNotepad();

private:
    Ui::FilePathEditor *ui;
    QStringList filters_;
    QFileDialog::AcceptMode acceptMode_;
    QFileDialog::FileMode fileMode_;
    QModelIndex modelIndex_;
};
