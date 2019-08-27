#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <gui.h>
#include <terminal.h>
#include <QObject>

class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager();
private:
    GUI gui_;
    Terminal terminal_;

    bool debug_mode_ = false;       // flag display is debug mode enabled
    bool repeat_mode_ = true;      // flag display repeat mode

private slots:
    void process_command(CommandDescription desc);
};

#endif // GAMEMANAGER_H
