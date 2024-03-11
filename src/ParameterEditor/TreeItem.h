
#ifndef QML_TREEVIEW_TREE_ITEM_H
#define QML_TREEVIEW_TREE_ITEM_H

#include "AbstractItem.h"

/*!
 * This class represents a node of the TreeModel.
 * The items are meant to be managed from the TreeModel, thus is only allowed
 * to modify the stored data.
 * Parenting and deletion are dealt from the TreeModel. Deleting a TreeItem
 * will call the delete for each child node.
 */
class TreeItem : public AbstractItem{

    friend class TreeModel;

public:
    TreeItem()
      : m_ParentItem(nullptr){};
    explicit TreeItem(const QVariant& data) 
      : AbstractItem(data), m_ParentItem(nullptr){};
    ~TreeItem();

    virtual int ChildCount() const override;
    virtual int Row() const override;
    virtual bool IsLeaf() const override;
    virtual int Depth() const override;
    
    TreeItem* GetChild(int row) const{

      if (row >= 0 && row < m_ChildItems.size()) return m_ChildItems[row];
      return nullptr;
    }

public:
    TreeItem* ParentItem();
    void SetParentItem(TreeItem* parentItem);

    void AppendChild(TreeItem* item);
    void RemoveChild(TreeItem* item);

    TreeItem* Child(int row);

private:
    TreeItem*          m_ParentItem;
    QVector<TreeItem*> m_ChildItems;
};

#endif // QML_TREEVIEW_TREE_ITEM_H