#include "AbstractItem.h"

AbstractItem::AbstractItem()
    : m_ItemData()
{}

AbstractItem::AbstractItem(const QVariant& data)
    : m_ItemData(data)
{}

const QVariant& AbstractItem::Data() const{
    return m_ItemData;
}

void AbstractItem::SetData(const QVariant& data){
    m_ItemData = data;
}