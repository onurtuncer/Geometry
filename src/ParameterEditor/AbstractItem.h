#ifndef QML_ABSTRACT_ITEM_H
#define QML_ABSTRACT_ITEM_H

#include <QVariant>

class AbstractItem {
   
public:
    AbstractItem();
    explicit AbstractItem(const QVariant& data);
    ~AbstractItem() = default;

    const QVariant& Data() const;
    void SetData(const QVariant& data);
    virtual int ChildCount() const = 0;
    virtual int Row() const = 0;
    virtual bool IsLeaf() const = 0; 
    virtual int Depth() const = 0;
    
private:
    QVariant               m_ItemData;
};

#endif // QML_ABSTRACT_ITEM_H