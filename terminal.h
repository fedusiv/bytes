#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>

#define MAP_SIZE 8

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
    BOT_ADD,
    BOT_ADD_DEBUG,  // add in debug mode
    BOT_ADD_REPEAT,  // add with repeat
    UNRECOGNISED
};

struct CommandDescription
{
    CommandType type;
    int x;
    int y;
    bool debug;
    QString string;
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


signals:
    void command_ready(CommandDescription desc);
public slots:
    void parse_command(QString command);
    QString add_digits_to_string(int x, int y);

private:

    bool debug_mode_ = false;
    bool repeat_mode_ = true;

    void parse_command_bot(QStringList list);

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

};

#endif // TERMINAL_H
