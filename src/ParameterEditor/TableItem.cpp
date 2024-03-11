
#include "TableItem.h"


TableItem::~TableItem(){

    qDeleteAll(m_ChildItems);
}

TableItem* TableItem::ParentItem(){
    
    return m_ParentItem;
}

void TableItem::SetParentItem(TableItem* parentItem){

    m_ParentItem = parentItem;
}

void TableItem::AppendChild(TableItem* item){

    if (item && !m_ChildItems.contains(item)) {
        m_ChildItems.append(item);
    }
}

void TableItem::RemoveChild(TableItem* item){

    if (item) {
        m_ChildItems.removeAll(item);
    }
}

TableItem* TableItem::Child(int row){

    return m_ChildItems.value(row);
}

int TableItem::ChildCount() const{

    return m_ChildItems.count();
}

bool TableItem::IsLeaf() const{

    return m_ChildItems.isEmpty();
}

int TableItem::Depth() const{

    int depth = 0;
    TableItem* anchestor = m_ParentItem;
    while (anchestor) {
        ++depth;
        anchestor = anchestor->ParentItem();
    }

    return depth;
}

int TableItem::Row() const{

    if (m_ParentItem) {
        return m_ParentItem->m_ChildItems.indexOf(const_cast<TableItem*>(this));
    }

    return 0;
}