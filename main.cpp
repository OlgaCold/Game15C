#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QQmlContext>

#include "gamemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<GameModel>("Game", 1, 0, "GameModel");

    //GameModel gameModel;


    QQmlApplicationEngine engine;
    //engine.rootContext()->setContextProperty(QStringLiteral("gameModel"), &gameModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
