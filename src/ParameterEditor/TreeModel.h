
#ifndef QML_TREEVIEW_TREE_MODEL_H
#define QML_TREEVIEW_TREE_MODEL_H

#include "TreeItem.h"

#include <QAbstractItemModel>

/*!
 * The Tree Model works as List Model, using one column and using the row information
 * referred to the parent node.
 */
class TreeModel : public QAbstractItemModel{

    Q_OBJECT

public:
    explicit TreeModel(QObject* parent = nullptr);
    ~TreeModel() override;

public:
    int rowCount(const QModelIndex& index) const override;
    int columnCount(const QModelIndex& index) const override;

    QModelIndex index(int row, int column, const QModelIndex& parent) const override;
    QModelIndex parent(const QModelIndex& childIndex) const override;

    QVariant data(const QModelIndex& index, int role = 0) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

public:

    void AddTopLevelItem(TreeItem* child);
    void AddItem(TreeItem* parent, TreeItem* child);
    void RemoveItem(TreeItem* item);
    TreeItem* RootItem() const;

    Q_INVOKABLE int depth(const QModelIndex& index) const;
    Q_INVOKABLE void clear();
    Q_INVOKABLE QModelIndex rootIndex();

private:
    TreeItem* InternalPointer(const QModelIndex& index) const;

private:
    TreeItem* m_RootItem;
};

#endif // QML_TREEVIEW_TREE_MODEL_H
