#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>

enum CommandsEnum
{
    Help,
    Bot,
    Scanner,
    Virus,
    SizeCommandsList
};

static QString CommandsNames[]=
{
    "help",
    "bot",
    "scan",
    "virus"
};

enum class CommandType
{
    HELP,
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
    QString const tmp_unrec = "Unrecognised command please enter <help>";
};

#endif // TERMINAL_H
