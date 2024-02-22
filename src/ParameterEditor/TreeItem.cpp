#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

class TreeItem : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QVariantList children READ children NOTIFY childrenChanged)

public:
    TreeItem(const QString& name, const QVariantList& children, QObject* parent = nullptr)
        : QObject(parent), m_name(name), m_children(children) {}

    QString name() const { return m_name; }
    QVariantList children() const { return m_children; }

    Q_INVOKABLE QVariant getChild(int index) const {
        if (index >= 0 && index < m_children.size())
            return m_children.at(index);
        return QVariant();
    }

signals:
    void childrenChanged();

private:
    QString m_name;
    QVariantList m_children;
};

class TreeModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QVariantList rootItem READ rootItem NOTIFY rootItemChanged)

public:
    TreeModel(QObject* parent = nullptr) : QObject(parent) {}

    void buildModel(const QJsonObject& object) {
        m_rootItem = buildTree(object);
        emit rootItemChanged();
    }

    QVariantList rootItem() const { return m_rootItem; }

signals:
    void rootItemChanged();

private:
    QVariantList m_rootItem;

    QVariantList buildTree(const QJsonObject& object) {
        QVariantList children;
        for (auto it = object.begin(); it != object.end(); ++it) {
            const QString& key = it.key();
            const QJsonValue& value = it.value();

            QVariant child;
            if (value.isObject()) {
                child = QVariant::fromValue(new TreeItem(key, buildTree(value.toObject()), this));
            } else if (value.isArray()) {
                QVariantList arrayChildren;
                for (const QJsonValue& arrayValue : value.toArray()) {
                    if (arrayValue.isObject()) {
                        arrayChildren.append(QVariant::fromValue(new TreeItem(key, buildTree(arrayValue.toObject()), this)));
                    } else {
                        arrayChildren.append(arrayValue.toVariant());
                    }
                }
                child = QVariant::fromValue(new TreeItem(key, arrayChildren, this));
            } else {
                child = QVariant::fromValue(new TreeItem(key, QVariantList{ value.toVariant() }, this));
            }

            children.append(child);
        }
        return children;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QString jsonData = R"(
        {
          "machine": {
            "buses": {
              "01": {
                "ioModule": {
                  "01": {
                    "address": {
                      "type": "unsigned int",
                      "value": 3
                    },
                    "analogInputMappingStartIndex": {
                      "type": "uint8_t",
                      "value": 0
                    },
                    "analogOutputMappingStartIndex": {
                      "type": "uint8_t",
                      "value": 0
                    }
                  }
                }
              }
            }
          }
        }
    )";

    QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject jsonObject = doc.object();

    TreeModel model;
    model.buildModel(jsonObject);

    engine.rootContext()->setContextProperty("treeModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#include "main.moc"
