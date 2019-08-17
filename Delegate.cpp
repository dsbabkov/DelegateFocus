#include "Delegate.h"
#include "FilePathEditor.h"

Delegate::Delegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return new FilePathEditor(parent, index);
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto filePathEditor = dynamic_cast<FilePathEditor *> (editor);
    filePathEditor->setPath(index.data().toString());
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto filePathEditor = dynamic_cast<FilePathEditor *>(editor);
    model->setData(index, filePathEditor->path());
}
