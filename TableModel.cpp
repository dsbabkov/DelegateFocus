#include "TableModel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex &) const
{
    return 1;
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 1;
}

QVariant TableModel::data(const QModelIndex &, int role) const
{
    if (role == Qt::EditRole || role == Qt::DisplayRole)
        return myData;

    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole) {
        return QAbstractTableModel::setData(index, value, role);
    }
    myData = value.toString();
    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
