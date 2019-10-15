#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <gui.h>
#include <terminal.h>
#include <socket.h>
#include <QObject>



class GameManager : public QObject
{
    Q_OBJECT
public:
    GameManager();
private:
    GUI gui_;
    Terminal terminal_;
    Socket socket_;

    bool debug_mode_ = false;       // flag display is debug mode enabled
    bool repeat_mode_ = true;      // flag display repeat mode

    void process_command_bot_add(CommandDescription desc);
    void process_connect_to_server(CommandDescription desc);


private slots:
    void process_command(CommandDescription desc);
};

#endif // GAMEMANAGER_H
