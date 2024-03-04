
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



void loadParameter(const QString& paramName, const QVariant& paramValue, TreeModel* model) {
    
    QStringList hierarchy = paramName.split(".");
    TreeItem* parent = model->rootItem(); // Assuming root is the parent initially

    // Iterate through the hierarchy, adding nodes as necessary
    for (const QString& nodeName : hierarchy) {
   
        bool nodeExists = false;
        for (int i = 0; i < parent->childCount(); ++i) {
            if (parent->getChild(i)->data().value<ParameterEntry>().key() == nodeName) {
                parent = parent->getChild(i);
                nodeExists = true;
                break;
            }
        }

        if (!nodeExists) {
            ParameterEntry entry(nodeName, QVariant(), -1); // Here you might want to pass the appropriate QVariant for the value
            TreeItem* child = new TreeItem(QVariant::fromValue(entry));
            model->addItem(parent, child);
            parent = child;
        }
    }

    // Check if the final parameter node already exists
    bool finalNodeExists = false;
    for (int i = 0; i < parent->childCount(); ++i) {
        if (parent->getChild(i)->data().value<ParameterEntry>().key() == hierarchy.last()) {
            finalNodeExists = true;
            break;
        }
    }

    // Add the final parameter node if it doesn't exist already
    if (!finalNodeExists) {
        ParameterEntry entry(hierarchy.last(), paramValue, 0);
        TreeItem* parameterNode = new TreeItem(QVariant::fromValue(entry));
        model->addItem(parent, parameterNode);
    }

    // // Add the final parameter node
    // ParameterEntry entry(hierarchy.last(), paramValue, 0);
    // TreeItem* parameterNode = new TreeItem(QVariant::fromValue(entry));
    // model->addItem(parent, parameterNode);
}

void populateModelFromParameterManager(Controller::ParameterManager& paramManager, TreeModel* parameterModel) {
    
    for (const auto& pair : paramManager.GetParameters()) {
        const std::string& path = pair.first;
        const QWrappedParameter& wrappedParam = QWrappedParameter::fromWrappedParameter(pair.second);
        const QVariant value = wrappedParam.toQVariant();
        loadParameter(QString::fromStdString(path), value, parameterModel);
    }
}


/* void populateModel(TreeModel& model)
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
 */

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
  pm1.AddParameter("offsets.g54"              , Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
  pm1.AddParameter("offsets.g55"              , Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
  pm1.AddParameter("offsets.g56"              , Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
  pm1.AddParameter("offsets.g57"              , Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
  pm1.AddParameter("offsets.g58"              , Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
  pm1.AddParameter("offsets.g59"              , Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
  pm1.AddParameter("offsets.activeOffset"     , Parameter<std::string>("g54")); 
  pm1.AddParameter("tools.T101.diameter"      , Parameter<double>(10.0));
  pm1.AddParameter("tools.T101.lengthOffset"  , Parameter<double>(0.0));
  pm1.AddParameter("tools.T102.diameter"      , Parameter<double>(10.0));
  pm1.AddParameter("tools.T102.lengthOffset"  , Parameter<double>(0.0));
  pm1.AddParameter("tools.T103.diameter"      , Parameter<double>(10.0));
  pm1.AddParameter("tools.T103.lengthOffset"  , Parameter<double>(0.0));
  pm1.AddParameter("tools.T104.diameter"      , Parameter<double>(10.0));
  pm1.AddParameter("tools.T104.lengthOffset"  , Parameter<double>(0.0));
  pm1.AddParameter("tools.T105.diameter"      , Parameter<double>(10.0));
  pm1.AddParameter("tools.T105.lengthOffset"  , Parameter<double>(0.0));
  pm1.AddParameter("tools.T106.diameter"      , Parameter<double>(10.0));
  pm1.AddParameter("tools.T106.lengthOffset"  , Parameter<double>(0.0));
  pm1.AddParameter("tools.T107.diameter"      , Parameter<double>(10.0));
  pm1.AddParameter("tools.T107.lengthOffset"  , Parameter<double>(0.0));


QGuiApplication app(argc, argv);
QQmlApplicationEngine engine;

QObject::connect(&engine, &QQmlApplicationEngine::warnings, [](const QList<QQmlError> &warnings) {
    for (const auto &warning : warnings) {
        qDebug() << "QML Warning:" << warning.toString();
    }
});
  
qmlRegisterType<TreeModel>("QMLTreeView", 1, 0, "TreeModel");

auto parameterModel = new TreeModel(&engine); // Assuming you have a parent object for your tree model
    
populateModelFromParameterManager(pm1, parameterModel);

// loadParameter(QString("machine.number_of_channels"), QWrappedParameter(Parameter<uint8_t>(1)).toQVariant(), parameterModel);
// loadParameter(QString("channels.01.type"), QWrappedParameter(Parameter<int>(100)).toQVariant(), parameterModel);
// loadParameter(QString("channels.01.number_of_axes"), QWrappedParameter(Parameter<int>(3)).toQVariant(), parameterModel);
// loadParameter(QString("channels.01.trajectory.contouring_enabled"), QWrappedParameter(Parameter<bool>(true)).toQVariant(), parameterModel);
// loadParameter(QString("channels.01.servo_names"), QWrappedParameter(Parameter<std::vector<std::string>>({"01","02","03"})).toQVariant(), parameterModel);

engine.rootContext()->setContextProperty("parameterModel", parameterModel);

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
