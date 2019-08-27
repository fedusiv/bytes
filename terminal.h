#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>



enum CommandsEnum
{
    Help,
    Clean,
    Debug,
    Repeat,
    Bot,
    Scanner,
    Virus,
    SizeCommandsList
};

static QString CommandsNames[]=
{
    "help",
    "clean",
    "debug",
    "repeat",
    "bot",
    "scan",
    "virus"
};

enum class CommandType
{
    HELP,
    CLEAN,
    DEBUG_MODE,
    REPEAT_MODE,
    ADD_BOT,
    ADD_BOT_ADD_BOT_DEBUG,
    ADD_BOT_DEBUG,
    UNRECOGNISED
};

struct CommandDescription
{
    CommandType type;
    int x;
    int y;
    bool status;
    QString string;
};

class Terminal : public QObject
{
    Q_OBJECT

public:
    Terminal();

signals:
    void command_ready(CommandDescription desc);
public slots:
    void parse_command(QString command);


private:

    bool debug_mode_ = false;
    bool repeat_mode_ = true;

    QString const tmp_unrec ="Unrecognised command please enter <help>";
    QString const tmp_help =
           "clean - remove everything from terminal\n\
debug - on|off debug mode\n\
repeat - on|off to repeat actions on debug map";
    QString tmp_debug_mode_on = "Set to debug mode";
    QString tmp_debug_mode_off = "Exit from debug mode";
    QString tmp_repeat_mode_on = "Repeat to debug mode on";
    QString tmp_repeat_mode_off = "Repeat to debug mode off";


};

#endif // TERMINAL_H
