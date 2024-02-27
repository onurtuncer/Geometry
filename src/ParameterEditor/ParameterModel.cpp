#include <QAbstractItemModel>
#include <QStringList>
#include <QVariant>

#include "Parameter.h"

//TODO delete this file!!!

class ParameterModel : public QAbstractItemModel {
    Q_OBJECT
public:
    ParameterModel(QObject *parent = nullptr) : QAbstractItemModel(parent) {
        // Root item for the model
        rootItem = new ParameterItem("Root", nullptr);
        // Add parameters to the model
        addParameters();
    }

    // Return the number of rows (children) under a given parent
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        if (!parent.isValid())
            return rootItem->childCount();
        ParameterItem *parentItem = getItem(parent);
        return parentItem ? parentItem->childCount() : 0;
    }

    // Return the number of columns in the model
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return 2; // Assuming two columns: Name and Value
    }

    // Return data to be displayed in a specific QModelIndex
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid())
            return QVariant();

        if (role == Qt::DisplayRole) {
            ParameterItem *item = getItem(index);
            if (item) {
                if (index.column() == 0)
                    return item->name();
                else if (index.column() == 1)
                    return item->value().toString(); // Convert value to string
            }
        }

        return QVariant();
    }

    // Return the index of the item in the model with the given row, column, and parent index
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override {
        if (!hasIndex(row, column, parent))
            return QModelIndex();

        ParameterItem *parentItem = getItem(parent);
        if (parentItem && row < parentItem->childCount())
            return createIndex(row, column, parentItem->child(row));

        return QModelIndex();
    }

    // Return the parent index of the item with the given index
    QModelIndex parent(const QModelIndex &index) const override {
        if (!index.isValid())
            return QModelIndex();

        ParameterItem *childItem = getItem(index);
        if (!childItem)
            return QModelIndex();

        ParameterItem *parentItem = childItem->parent();

        if (parentItem == rootItem)
            return QModelIndex();

        return createIndex(parentItem->row(), 0, parentItem);
    }

private:
    // Define your custom ParameterItem class here
    // It represents an item in the model
    class ParameterItem {
    public:
        ParameterItem(const QString &name, ParameterItem *parent)
            : itemName(name), itemParent(parent) {} // use this for root node
        ParameterItem(const QString &name, ParameterItem *parent, Controller::WrappedParameter wrapped) // this one for all other nodes
            : itemName(name), itemParent(parent), itemWrapped(wrapped) {}

        void appendChild(ParameterItem *child) {
            childItems.append(child);
        }

        ParameterItem *child(int row) const {
            return row >= 0 && row < childCount() ? childItems[row] : nullptr;
        }

        int childCount() const {
            return childItems.size();
        }

        int row() const {
            if (itemParent)
                return itemParent->childItems.indexOf(const_cast<ParameterItem*>(this));
            return 0;
        }

        QString name() const {
            return itemName;
        }

        QVariant value() const {
            return itemValue;
        }

        ParameterItem *parent() const {
            return itemParent;
        }

    private:
        QString itemName;
        QVariant itemValue;
        ParameterItem *itemParent;
        QList<ParameterItem*> childItems;
        Controller::WrappedParameter itemWrapped;
    };

    // Private function to get the ParameterItem for a given QModelIndex
    ParameterItem *getItem(const QModelIndex &index) const {
        if (index.isValid()) {
            ParameterItem *item = static_cast<ParameterItem*>(index.internalPointer());
            if (item)
                return item;
        }
        return rootItem;
    }

    // Function to add parameters to the model
    void addParameters() {
        // // Example parameters
        ParameterItem *channels = new ParameterItem("Channels", rootItem);
        ParameterItem* tools    = new ParameterItem("Tools", rootItem);
        
        // rootItem->appendChild(channels);
        // ParameterItem *channel1 = new ParameterItem("Channel 1", channels);
        // channels->appendChild(channel1);
        // ParameterItem *type = new ParameterItem("Type", channel1);
        // type->itemValue = QVariant(0);
        // channel1->appendChild(type);
        // ParameterItem *axis = new ParameterItem("Turning Axis", channel1);
        // axis->itemValue = QVariant('C');
        // channel1->appendChild(axis);
        // // Add more parameters as needed
    }

    ParameterItem *rootItem;
};

#include "ParameterModel.moc"
