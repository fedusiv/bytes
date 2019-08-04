#ifndef GUI_H
#define GUI_H

#include <QQmlApplicationEngine>

class GUI
{
public:
    GUI();
    void registerObject(QObject *obj, const QString& qmlName);
    void run();
private:
    QQmlApplicationEngine engine_;
};

#endif // GUI_H
