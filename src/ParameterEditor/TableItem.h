
#ifndef QML_TABLEVIEW_TABLE_ITEM_H
#define QML_TABLEVIEW_TABLE_ITEM_H

#include "AbstractItem.h"

/*!
 * This class represents a node of the TableModel.
 * The items are meant to be managed from the TableModel, thus is only allowed
 * to modify the stored data. Parenting and deletion are dealt from the TreeModel. 
 */
class TableItem : public AbstractItem{

    friend class TableModel;

public:
     TableItem()
      : m_ParentItem(nullptr){};
    explicit TableItem(const QVariant& data) 
      : AbstractItem(data), m_ParentItem(nullptr){};
    ~TableItem();

    virtual int ChildCount() const override;
    virtual int Row() const override;
    virtual bool IsLeaf() const override;
    virtual int Depth() const override;
    
    TableItem* GetChild(int row) const{

      if (row >= 0 && row < m_ChildItems.size()) return m_ChildItems[row];
      return nullptr;
    }

private:
    TableItem* ParentItem();
    void SetParentItem(TableItem* parentItem);

    void AppendChild(TableItem* item);
    void RemoveChild(TableItem* item);

    TableItem* Child(int row);

private:
    TableItem*          m_ParentItem;
    QVector<TableItem*> m_ChildItems;
};

#endif // QML_TABLEVIEW_TABLE_ITEM_H