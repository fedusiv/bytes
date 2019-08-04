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
    engine_.load("qrc:/main.qml");
}
