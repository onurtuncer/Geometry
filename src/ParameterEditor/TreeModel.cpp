#include "TreeModel.h"

TreeModel::TreeModel(QObject* parent)
    : QAbstractItemModel(parent),
      m_RootItem{new TreeItem()}{}

TreeModel::~TreeModel(){

    delete m_RootItem;
}

int TreeModel::rowCount(const QModelIndex& parent) const{

    if (!parent.isValid()) {
        return m_RootItem->ChildCount();
    }

    return InternalPointer(parent)->ChildCount();
}

int TreeModel::columnCount(const QModelIndex& /*parent*/) const{

    // This is basically flatten as a list model
    return 1;
}

QModelIndex TreeModel::index(const int row, const int column, const QModelIndex& parent) const{

    if (!hasIndex(row, column, parent)) {
        return {};
    }

    TreeItem* item = m_RootItem;
    if (parent.isValid()) {
        item = InternalPointer(parent);
    }

    if (auto child = item->Child(row)) {
        return createIndex(row, column, child);
    }

    return {};
}

QModelIndex TreeModel::parent(const QModelIndex& index) const{

    if (!index.isValid()) {
        return {};
    }

    TreeItem* childItem = InternalPointer(index);
    TreeItem* parentItem = childItem->ParentItem();

    if (!parentItem) {
        return {};
    }

    if (parentItem == m_RootItem) {
        return {};
    }

    return createIndex(parentItem->Row(), 0, parentItem);
}

QVariant TreeModel::data(const QModelIndex& index, const int role) const{

    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    return InternalPointer(index)->Data();
}

bool TreeModel::setData(const QModelIndex& index, const QVariant& value, int /*role*/){

    if (!index.isValid()) {
        return false;
    }

    if (auto item = InternalPointer(index)) {
        item->SetData(value);
        emit dataChanged(index, index, {Qt::EditRole});
    }

    return false;
}

void TreeModel::AddTopLevelItem(TreeItem* child){

    if (child) {
        AddItem(m_RootItem, child);
    }
}

void TreeModel::AddItem(TreeItem* parent, TreeItem* child){

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

void TreeModel::RemoveItem(TreeItem* item){

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

TreeItem* TreeModel::RootItem() const{

    return m_RootItem;
}

QModelIndex TreeModel::rootIndex(){

    return {};
}

int TreeModel::depth(const QModelIndex& index) const{

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

void TreeModel::clear(){

    emit layoutAboutToBeChanged();
    beginResetModel();
    delete m_RootItem;
    m_RootItem = new TreeItem();
    endResetModel();
    emit layoutChanged();
}

TreeItem* TreeModel::InternalPointer(const QModelIndex& index) const{

    return static_cast<TreeItem*>(index.internalPointer());
}