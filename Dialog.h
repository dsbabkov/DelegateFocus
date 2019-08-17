#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "TableModel.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    void acceptDataFromModel(const QModelIndex &);

private:
    Ui::Dialog *ui;
    QString dataFromModel;
    TableModel model{this};


    // QDialog interface
public slots:
    void accept() override;
};

#endif // DIALOG_H
