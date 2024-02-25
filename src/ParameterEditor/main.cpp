#include "json_entry.h"
#include "parameter_entry.h"
#include "tree_model.h"

#include <QFile>
#include <QGuiApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ParameterManager.h"
#include "QWrappedParameter.h"


void loadValue(const QJsonValue& value, TreeItem* parent, TreeModel* model)
{
    if (value.isObject()) {
        auto object = value.toObject();
        for (auto it = object.begin(); it != object.end(); ++it) {
            JsonEntry entry;
            entry.setKey(it.key());
            entry.setType(QJsonValue::Object);
            if (it.value().isArray() || it.value().isObject()) {
                auto child = new TreeItem(QVariant::fromValue(entry));
                loadValue(it.value(), child, model);
                model->addItem(parent, child);
            } else {
                entry.setValue(it.value().toVariant());
                auto child = new TreeItem(QVariant::fromValue(entry));
                model->addItem(parent, child);
            }
        }
    } else if (value.isArray()) {
        int index = 0;
        auto array = value.toArray();
        for (auto&& element : array) {
            JsonEntry entry;
            entry.setKey("[" + QString::number(index) + "]");
            entry.setType(QJsonValue::Array);
            auto child = new TreeItem(QVariant::fromValue(entry));
            model->addItem(parent, child);
            loadValue(element, child, model);
            ++index;
        }
    } else {
        JsonEntry entry;
        entry.setValue(value.toVariant());
        entry.setType(value.type());
        auto child = new TreeItem(QVariant::fromValue(entry));
        model->addItem(parent, child);
    }
}

// void loadParameter(Controller::WrappedParameter wrapped,  TreeItem* parent, TreeModel* model)
// {
//     ParameterEntry entry;
//     entry.setValue(value.toVariant());
//     entry.setType(value.type());
//     auto child = new TreeItem(QVariant::fromValue(entry));
//     model->addItem(parent, child);  
// }


void populateModel(TreeModel& model)
{
    QFile jsonFile{":/sample.json"};
    if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "error: json file cannot be open";
        return;
    }

    QJsonParseError error;
    auto doc = QJsonDocument::fromJson(jsonFile.readAll(), &error);
    qDebug() << "loading json file:" << error.errorString();

    auto root = doc.isArray() ? QJsonValue(doc.array()) : QJsonValue(doc.object());
    loadValue(root, model.rootItem(), &model);
}

int main(int argc, char* argv[]){

 using namespace Controller;

  ParameterManager pm1;

  pm1.AddParameter("machine.number_of_channels", Parameter<uint8_t>(1));
  pm1.AddParameter("channels.01.type", Parameter<int>(0)); // 0: milling, 1: turning
  pm1.AddParameter("channels.01.turning_axis", Parameter<char>('C'));
  pm1.AddParameter("channels.01.number_of_axes",       Parameter<int>(3));
  pm1.AddParameter("channels.01.kinematics_type",      Parameter<int>(0)); 
  pm1.AddParameter("channels.01.trajectory.jerklimit" , Parameter<double>(50000));
  pm1.AddParameter("channels.01.trajectory.contouring_enabled", Parameter<bool>(false));
  pm1.AddParameter("channels.01.trajectory.microspline_enabled", Parameter<bool>(true));
  pm1.AddParameter("channels.01.trajectory.cornering_tolerance",  Parameter<double>(0.4));
  pm1.AddParameter("channels.01.trajectory.sample_time",  Parameter<double>(0.001));
  pm1.AddParameter("channels.01.trajectory.acceleration_limit",  Parameter<double>(4000));
  pm1.AddParameter("channels.01.trajectory.deceleration_limit",  Parameter<double>(4000));
  pm1.AddParameter("channels.01.servo_names", Parameter<std::vector<std::string>>({"01","02","03"}));
  pm1.AddParameter("bus.io_names", Parameter<std::vector<std::string>>({"01"}));

 auto abuk = Controller::WrappedParameter(Controller::Parameter<bool>(true));
 auto subuk = QWrappedParameter(abuk);

 auto abuk2 = Controller::WrappedParameter(Controller::Parameter<int>(10));
 auto subuk2 = QWrappedParameter(abuk2);

 // Convert QWrappedParameter to QVariant
QVariant variant = subuk.toQVariant();
QVariant variant2 = subuk2.toQVariant();

qDebug() << "Value of subuk:" << variant;
qDebug() << "Value of subuk2:" << variant2;

variant2 = 3;

subuk2.fromQVariant(3);
QVariant variant3 = subuk2.toQVariant();
qDebug() << "New Value of subuk2:" << variant3;

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    
    qmlRegisterType<TreeModel>("QMLTreeView", 1, 0, "TreeModel");

    auto jsonModel = new TreeModel(&engine);
    populateModel(*jsonModel);

    engine.rootContext()->setContextProperty("jsonModel", jsonModel);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
