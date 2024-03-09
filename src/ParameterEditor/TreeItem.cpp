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

#include "TreeItem.h"

TreeItem::TreeItem()
    : m_ItemData()
    , m_ParentItem(nullptr)
{}

TreeItem::TreeItem(const QVariant& data)
    : m_ItemData(data)
    , m_ParentItem(nullptr)
{}

TreeItem::~TreeItem()
{
    qDeleteAll(m_ChildItems);
}

TreeItem* TreeItem::ParentItem()
{
    return m_ParentItem;
}

void TreeItem::SetParentItem(TreeItem* parentItem)
{
    m_ParentItem = parentItem;
}

void TreeItem::AppendChild(TreeItem* item)
{
    if (item && !m_ChildItems.contains(item)) {
        m_ChildItems.append(item);
    }
}

void TreeItem::RemoveChild(TreeItem* item)
{
    if (item) {
        m_ChildItems.removeAll(item);
    }
}

TreeItem* TreeItem::Child(int row)
{
    return m_ChildItems.value(row);
}

int TreeItem::ChildCount() const
{
    return m_ChildItems.count();
}

const QVariant& TreeItem::Data() const
{
    return m_ItemData;
}

void TreeItem::SetData(const QVariant& data)
{
    m_ItemData = data;
}

bool TreeItem::IsLeaf() const
{
    return m_ChildItems.isEmpty();
}

int TreeItem::Depth() const
{
    int depth = 0;
    TreeItem* anchestor = m_ParentItem;
    while (anchestor) {
        ++depth;
        anchestor = anchestor->ParentItem();
    }

    return depth;
}

int TreeItem::Row() const
{
    if (m_ParentItem) {
        return m_ParentItem->m_ChildItems.indexOf(const_cast<TreeItem*>(this));
    }

    return 0;
}
