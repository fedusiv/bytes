#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <gamemanager.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    GameManager game_manager;

    return app.exec();
}
