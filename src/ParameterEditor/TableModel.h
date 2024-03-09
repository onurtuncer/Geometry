
#ifndef QML_TABLEVIEW_TABLE_MODEL_H
#define QML_TABLEVIEW_TABLE_MODEL_H

#include "TableItem.h"

#include <QAbstractItemModel>

/*!
 * The Table Model works as List Model, using one column and using the row information
 * referred to the parent node.
 */

class TableModel : public QAbstractItemModel{

    Q_OBJECT

public:
    explicit TableModel(QObject* parent = nullptr);
    ~TableModel() override;

public:
    int rowCount(const QModelIndex& index) const override;
    int columnCount(const QModelIndex& index) const override;

    QModelIndex index(int row, int column, const QModelIndex& parent) const override;
    QModelIndex parent(const QModelIndex& childIndex) const override;

    QVariant data(const QModelIndex& index, int role = 0) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

public:
    void AddTopLevelItem(TableItem* child); 
    void RemoveItem(TableItem* item);
    TableItem* RootItem() const;

    Q_INVOKABLE int depth(const QModelIndex& index) const;
    Q_INVOKABLE void clear();
    Q_INVOKABLE QModelIndex rootIndex();

private:
    void AddItem(TableItem* parent, TableItem* child);
    TableItem* InternalPointer(const QModelIndex& index) const;

private:
    TableItem* m_RootItem;
};

#endif // QML_TABLEVIEW_TABLE_MODEL_H