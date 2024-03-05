
#include "parameter_entry.h"
#include "tree_model.h"

#include <QFile>
#include <QGuiApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "QParameterManager.h"
#include "QWrappedParameter.h"

void setupParameters(QParameterManager* pm1) {

  using namespace Controller;

//   pm1.AddParameter("machine.number_of_channels", Parameter<uint8_t>(1));
  // pm1.AddParameter("channels.01.type", Parameter<int>(0)); // 0: milling, 1: turning
//   pm1.AddParameter("channels.01.turning_axis", Parameter<char>('C'));
  // pm1.AddParameter("channels.01.number_of_axes", Parameter<int>(3));
  // pm1.AddParameter("channels.01.kinematics_type", Parameter<int>(0));
//   pm1.AddParameter("channels.01.trajectory.jerklimit", Parameter<double>(50000));
  pm1->AddParameter("channels.01.trajectory.contouring_enabled", Parameter<bool>(false));
  pm1->AddParameter("channels.01.trajectory.microspline_enabled", Parameter<bool>(true));
//   pm1.AddParameter("channels.01.trajectory.cornering_tolerance", Parameter<double>(0.4));
//   pm1.AddParameter("channels.01.trajectory.sample_time", Parameter<double>(0.001));
//   pm1.AddParameter("channels.01.trajectory.acceleration_limit", Parameter<double>(4000));
//   pm1.AddParameter("channels.01.trajectory.deceleration_limit", Parameter<double>(4000));
//   pm1.AddParameter("channels.01.servo_names", Parameter<std::vector<std::string>>({"01", "02", "03"}));
  // pm1.AddParameter("bus.io_names", Parameter<std::vector<std::string>>({"01"}));
//   pm1.AddParameter("offsets.g54", Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
//   pm1.AddParameter("offsets.g55", Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
//   pm1.AddParameter("offsets.g56", Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
//   pm1.AddParameter("offsets.g57", Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
//   pm1.AddParameter("offsets.g58", Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
//   pm1.AddParameter("offsets.g59", Parameter<std::vector<double>>({0.0, 0.0, 0.0}));
  // pm1.AddParameter("offsets.activeOffset", Parameter<std::string>("g54"));
//   pm1.AddParameter("tools.T101.diameter", Parameter<double>(10.0));
//   pm1.AddParameter("tools.T101.lengthOffset", Parameter<double>(0.0));
//   pm1.AddParameter("tools.T102.diameter", Parameter<double>(10.0));
//   pm1.AddParameter("tools.T102.lengthOffset", Parameter<double>(0.0));
//   pm1.AddParameter("tools.T103.diameter", Parameter<double>(10.0));
//   pm1.AddParameter("tools.T103.lengthOffset", Parameter<double>(0.0));
//   pm1.AddParameter("tools.T104.diameter", Parameter<double>(10.0));
//   pm1.AddParameter("tools.T104.lengthOffset", Parameter<double>(0.0));
//   pm1.AddParameter("tools.T105.diameter", Parameter<double>(10.0));
//   pm1.AddParameter("tools.T105.lengthOffset", Parameter<double>(0.0));
//   pm1.AddParameter("tools.T106.diameter", Parameter<double>(10.0));
//   pm1.AddParameter("tools.T106.lengthOffset", Parameter<double>(0.0));
//   pm1.AddParameter("tools.T107.diameter", Parameter<double>(10.0));
//   pm1.AddParameter("tools.T107.lengthOffset", Parameter<double>(0.0));
}

void loadParameter(const QString& path, const QVariant& paramValue, int type, TreeModel* model) {
    
    QStringList hierarchy = path.split(".");
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
            ParameterEntry entry(nodeName, QVariant(), 0); // Here you might want to pass the appropriate QVariant for the value
            TreeItem* child = new TreeItem(QVariant::fromValue(entry));
            model->addItem(parent, child);
            parent = child;
        }
    }

    // Add the final parameter node
    ParameterEntry entry(hierarchy.last(), paramValue, type, path);
    TreeItem* parameterNode = new TreeItem(QVariant::fromValue(entry));
    model->addItem(parent, parameterNode);
}

void populateModelFromParameterManager(QParameterManager* paramManager, TreeModel* parameterModel) {
    
    for (const auto& pair : paramManager->GetParameters()) {
        const std::string& path = pair.first;
        const QWrappedParameter& wrappedParam = QWrappedParameter::fromWrappedParameter(pair.second);
        const QVariant value = wrappedParam.toQVariant();
        loadParameter(QString::fromStdString(path), value, static_cast<int>(wrappedParam.GetType()),  parameterModel);
    }
}

int main(int argc, char* argv[]){

  using namespace Controller;

  auto pm1 = QParameterManager::instance();
  setupParameters(pm1);
  
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  QObject::connect(&engine, &QQmlApplicationEngine::warnings, [](const QList<QQmlError> &warnings) {
    for (const auto &warning : warnings) {
        qDebug() << "QML Warning:" << warning.toString();
    }
  });
  
qmlRegisterType<TreeModel>("QMLTreeView", 1, 0, "TreeModel");

// Register QParameterManager with the QML engine
qmlRegisterSingletonInstance<QParameterManager>("QMLParameterManager", 1, 0, "QParameterManager", pm1);

auto parameterModel = new TreeModel(&engine); // Assuming you have a parent object for your tree model
    
populateModelFromParameterManager(pm1, parameterModel);

engine.rootContext()->setContextProperty("parameterModel", parameterModel);
engine.rootContext()->setContextProperty("parameterManager", pm1);

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