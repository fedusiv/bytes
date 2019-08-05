#ifndef GUI_H
#define GUI_H

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QColor>
class GUI : public QObject
{
    Q_OBJECT
public:
    GUI();
    void registerObject(QObject *obj, const QString& qmlName);
    void run();

public slots:
    void receive_string(QString string);
signals:
    void change_cell(QVariant my_color, int id);
private:
    QQmlApplicationEngine engine_;


};

#endif // GUI_H
