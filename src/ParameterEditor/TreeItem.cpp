
#include "TreeItem.h"

TreeItem::~TreeItem()
{
    qDeleteAll(m_ChildItems);
}

TreeItem* TreeItem::ParentItem()
{
    return m_ParentItem;
}

void TreeItem::SetParentItem(TreeItem* parentItem){
    m_ParentItem = parentItem;
}

void TreeItem::AppendChild(TreeItem* item){

    if (item && !m_ChildItems.contains(item)) {
        m_ChildItems.append(item);
    }
}

void TreeItem::RemoveChild(TreeItem* item){

    if (item) {
        m_ChildItems.removeAll(item);
    }
}

TreeItem* TreeItem::Child(int row)
{
    return m_ChildItems.value(row);
}

int TreeItem::ChildCount() const{

    return m_ChildItems.count();
}

bool TreeItem::IsLeaf() const
{
    return m_ChildItems.isEmpty();
}

int TreeItem::Depth() const{

    int depth = 0;
    TreeItem* anchestor = m_ParentItem;
    while (anchestor) {
        ++depth;
        anchestor = anchestor->ParentItem();
    }

    return depth;
}

int TreeItem::Row() const{

    if (m_ParentItem) {
        return m_ParentItem->m_ChildItems.indexOf(const_cast<TreeItem*>(this));
    }

    return 0;
}