#include "Dialog.h"
#include "ui_Dialog.h"
#include <QMessageBox>
#include "Delegate.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(&model, &TableModel::dataChanged, this, &Dialog::acceptDataFromModel);
    ui->tableView->setModel(&model);
    ui->tableView->setItemDelegate(new Delegate(ui->tableView));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::acceptDataFromModel(const QModelIndex &index)
{
    dataFromModel = index.data().toString();
}

void Dialog::accept()
{
    QMessageBox::information(this, "dataFromModel", dataFromModel, QMessageBox::Ok);
}
