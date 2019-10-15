#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>

#define MAP_SIZE 8

enum CommandsEnum
{
    Help,
    Clean,
    Start,
    Debug,
    Repeat,
    Bot,
    Scanner,
    Virus,
    Connect,
    SizeCommandsList
};

static QString CommandsNames[]=
{
    "help",
    "clean",
    "start",
    "debug",
    "repeat",
    "bot",
    "scan",
    "virus",
    "connect"
};

enum class CommandType
{
    HELP,
    CLEAN,
    START,
    DEBUG_MODE,
    REPEAT_MODE,
    BOT_ADD,
    CONNECT,
    UNRECOGNISED
};

struct CommandDescription
{
    CommandType type;
    int x;
    int y;
    bool debug;
    bool repeat;
    QString string;
    QString ip;
};


enum CommandsOptionsEnum
{
    Add,
    Remove,
    Debug_option,
    Repeat_option,
    SizeOptionsEnum
};

static QStringList CommandsOptions =
{
    "add",
    "rm",
    "-d",
    "-r"
};

class Terminal : public QObject
{
    Q_OBJECT

public:
    Terminal();
    QString bot_string(CommandDescription desc);
    QString debug_mode_string(bool mode);
    QString repeat_mode_string(bool mode);

signals:
    void command_ready(CommandDescription desc);
public slots:
    void parse_command(QString command);



private:
    QString add_digits_to_string(int x, int y);
    void command_desc_clear(CommandDescription * desc);
    bool debug_mode_ = false;
    bool repeat_mode_ = true;

    void parse_command_bot(QStringList list);
    void parse_connect_to_server(QStringList list);
    // this is really temporary. I hope
    QString const tmp_unrec ="Unrecognised command please enter <help>";
    QString const tmp_unrec_digit="Unrecognised digit values";
    QString const tmp_help =
           "clean - remove everything from terminal\n\
debug - on|off debug mode\n\
repeat - on|off to repeat actions on debug map\n\
bot - operation with unit: bot";
    QString tmp_debug_mode_on = "Set to debug mode";
    QString tmp_debug_mode_off = "Exit from debug mode";
    QString tmp_repeat_mode_on = "Repeat to debug mode on";
    QString tmp_repeat_mode_off = "Repeat to debug mode off";
    QString tmp_bot_add = "Add bot";
    QString tmp_bot_add_d = "Add bot in debug mode";
    QString tmp_bot_add_r = "Add bot with repeat to debug map";
    QString tmp_start = "Sending ready signal to start game";

};

#endif // TERMINAL_H
