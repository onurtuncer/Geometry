#include "TableModel.h"

TableModel::TableModel(QObject* parent)
    : QAbstractItemModel(parent)
    , m_RootItem{new TableItem()}
{}

TableModel::~TableModel(){

    delete m_RootItem;
}

int TableModel::rowCount(const QModelIndex& parent) const{

    if (!parent.isValid()) {
        return m_RootItem->ChildCount();
    }

    return InternalPointer(parent)->ChildCount();
}

int TableModel::columnCount(const QModelIndex& /*parent*/) const{

    // This is basically flatten as a list model
    return 1;
}

QModelIndex TableModel::index(const int row, const int column, const QModelIndex& parent) const{

    if (!hasIndex(row, column, parent)) {
        return {};
    }

    TableItem* item = m_RootItem;
    if (parent.isValid()) {
        item = InternalPointer(parent);
    }

    if (auto child = item->Child(row)) {
        return createIndex(row, column, child);
    }

    return {};
}

QModelIndex TableModel::parent(const QModelIndex& index) const{

    if (!index.isValid()) {
        return {};
    }

    TableItem* childItem = InternalPointer(index);
    TableItem* parentItem = childItem->ParentItem();

    if (!parentItem) {
        return {};
    }

    if (parentItem == m_RootItem) {
        return {};
    }

    return createIndex(parentItem->Row(), 0, parentItem);
}

QVariant TableModel::data(const QModelIndex& index, const int role) const{

    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    return InternalPointer(index)->Data();
}

bool TableModel::setData(const QModelIndex& index, const QVariant& value, int /*role*/){

    if (!index.isValid()) {
        return false;
    }

    if (auto item = InternalPointer(index)) {
        item->SetData(value);
        emit dataChanged(index, index, {Qt::EditRole});
    }

    return false;
}

void TableModel::AddTopLevelItem(TableItem* child){

    if (child) {
        AddItem(m_RootItem, child);
    }
}

void TableModel::AddItem(TableItem* parent, TableItem* child){

    if (!child || !parent) {
        return;
    }

    emit layoutAboutToBeChanged();

    if (child->ParentItem()) {
        beginRemoveRows(QModelIndex(), qMax(parent->ChildCount() - 1, 0), qMax(parent->ChildCount(), 0));
        child->ParentItem()->RemoveChild(child);
        endRemoveRows();
    }

    beginInsertRows(QModelIndex(), qMax(parent->ChildCount() - 1, 0), qMax(parent->ChildCount() - 1, 0));
    child->SetParentItem(parent);
    parent->AppendChild(child);
    endInsertRows();

    emit layoutChanged();
}

void TableModel::RemoveItem(TableItem* item){

    if (!item) {
        return;
    }

    emit layoutAboutToBeChanged();

    if (item->ParentItem()) {
        beginRemoveRows(QModelIndex(), qMax(item->ChildCount() - 1, 0), qMax(item->ChildCount(), 0));
        item->ParentItem()->RemoveChild(item);
        endRemoveRows();
    }

    emit layoutChanged();
}

TableItem* TableModel::RootItem() const{

    return m_RootItem;
}

QModelIndex TableModel::rootIndex(){

    return {};
}

int TableModel::depth(const QModelIndex& index) const{
    int count = 0;
    auto anchestor = index;
    if (!index.isValid()) {
        return 0;
    }
    while (anchestor.parent().isValid()) {
        anchestor = anchestor.parent();
        ++count;
    }

    return count;
}

void TableModel::clear(){

    emit layoutAboutToBeChanged();
    beginResetModel();
    delete m_RootItem;
    m_RootItem = new TableItem();
    endResetModel();
    emit layoutChanged();
}

TableItem* TableModel::InternalPointer(const QModelIndex& index) const{

    return static_cast<TableItem*>(index.internalPointer());
}