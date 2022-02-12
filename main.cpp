#include <QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QQmlContext>
#include <View.h>

#include <QApplication>
//Entry point of the application



int main(int argc, char *argv[])
{
    //Application attributes
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //The application class
    QApplication  app(argc, argv);

    //The QML Engine
    QQmlApplicationEngine engine;

    //Add to the root context
    View view;
    engine.rootContext()->setContextProperty("view", &view);


     //The URL of the QML file, notice this is a compiled resource
    const QUrl url(QStringLiteral("qrc:/window.qml"));

    //Connecting a signal and slot - making sure the object and url match
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    //The engine loading the QML file
    engine.load(url);


    //The application entering an event loop that keeps the application open
    return app.exec();
}

