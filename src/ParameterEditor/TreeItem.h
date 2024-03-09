/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2021 Maurizio Ingrassia
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef QML_TREEVIEW_TREE_ITEM_H
#define QML_TREEVIEW_TREE_ITEM_H

#include <QVariant>

/*!
 * This class represents a node of the TreeModel.
 * The items are meant to be managed from the TreeModel, thus is only allowed
 * to modify the stored data.
 * Parenting and deletion are dealt from the TreeModel. Deleting a TreeItem
 * will call the delete for each child node.
 */
class TreeItem
{
    friend class TreeModel;

public:
    TreeItem();
    explicit TreeItem(const QVariant& data);
    ~TreeItem();

    const QVariant& Data() const;
    void SetData(const QVariant& data);
    int ChildCount() const;
    int Row() const;
    bool IsLeaf() const;
    int Depth() const;
    
    TreeItem* GetChild(int row) const{

      if (row >= 0 && row < m_ChildItems.size()) return m_ChildItems[row];
      return nullptr;
    }

private:
    TreeItem* ParentItem();
    void SetParentItem(TreeItem* parentItem);

    void AppendChild(TreeItem* item);
    void RemoveChild(TreeItem* item);

    TreeItem* Child(int row);

private:
    QVariant           m_ItemData;
    TreeItem*          m_ParentItem;
    QVector<TreeItem*> m_ChildItems;
};

#endif // QML_TREEVIEW_TREE_ITEM_H