
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

auto variant4 = QWrappedParameter(Parameter<std::vector<std::string>>({"01","02","03"})).toQVariant();

qDebug() << "variant4:" << variant4;

QGuiApplication app(argc, argv);
QQmlApplicationEngine engine;


// auto parameterModel = new TreeModel(&engine);
// populateModel(*jsonModel);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  
    
    qmlRegisterType<TreeModel>("QMLTreeView", 1, 0, "TreeModel");


    auto parameterModel = new TreeModel(&engine); // Assuming you have a parent object for your tree model

loadParameter(QString("machine.number_of_channels"), QWrappedParameter(Parameter<uint8_t>(1)).toQVariant(), parameterModel);
loadParameter(QString("channels.01.type"), QWrappedParameter(Parameter<int>(100)).toQVariant(), parameterModel);
loadParameter(QString("channels.01.number_of_axes"), QWrappedParameter(Parameter<int>(3)).toQVariant(), parameterModel);
loadParameter(QString("channels.01.trajectory.contouring_enabled"), QWrappedParameter(Parameter<bool>(true)).toQVariant(), parameterModel);
loadParameter(QString("channels.01.servo_names"), QWrappedParameter(Parameter<std::vector<std::string>>({"01","02","03"})).toQVariant(), parameterModel);



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
