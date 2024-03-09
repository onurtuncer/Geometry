
#ifndef QML_TABLEVIEW_TABLE_ITEM_H
#define QML_TABLEVIEW_TABLE_ITEM_H

#include <QVariant>

/*!
 * This class represents a node of the TableModel.
 * The items are meant to be managed from the TableModel, thus is only allowed
 * to modify the stored data. Parenting and deletion are dealt from the TreeModel. 
 */
class TableItem
{
    friend class TableModel;

public:
    TableItem();
    explicit TableItem(const QVariant& data);
    ~TableItem();

    const QVariant& Data() const;
    void SetData(const QVariant& data);
    int ChildCount() const;
    int Row() const;
    bool IsLeaf() const;
    int Depth() const;
    
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
    QVariant           m_ItemData;
    TableItem*          m_ParentItem;
    QVector<TableItem*> m_ChildItems;
};

#endif // QML_TABLEVIEW_TABLE_ITEM_H