#include "gui.h"

GUI::GUI()
{

}

void GUI::registerObject(QObject *obj, const QString &qmlName)
{
    if(obj)
        {
            //engine_.rootContext()->setContextProperty(qmlName, obj);
        }
}

void GUI::run()
{
    auto ctx = engine_.rootContext();
    ctx->setContextProperty("gui",this);
    engine_.load("qrc:/main.qml");
}

void GUI::receive_string(QString string)
{
    emit receive_command(string);
}


