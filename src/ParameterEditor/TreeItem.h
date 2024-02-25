#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>

class TreeItem {
public:
    explicit TreeItem(const QString &data, TreeItem *parent = nullptr);
    ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parent();

private:
    QList<TreeItem*> childItems;
    QString itemData;
    TreeItem *parentItem;
};

#endif // TREEITEM_H

