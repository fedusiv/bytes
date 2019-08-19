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
    // changing content like bots
    void change_cell_content(QVariant my_color, int id);
    void change_cell_content_d(QVariant my_color, int id);
    // changing stuff like virus/antivirus
    void change_cell(QVariant my_color, int id);
    void change_cell_d(QVariant my_color, int id);
    // signal, what player entered command
    void receive_command(QString command);
    // signal to send string to console
    void append_string(QString string);
    // signal to clean terminal
    void clean_terminal();

private:
    QQmlApplicationEngine engine_;


};

#endif // GUI_H
