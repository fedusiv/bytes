#include "terminal.h"
#include <QDebug>
Terminal::Terminal()
{

}

void Terminal::parse_command(QString command)
{
    QStringList list = command.split(' ');
    CommandsEnum _command = CommandsEnum::SizeCommandsList;

    for ( int i = 0; i < CommandsEnum::SizeCommandsList; i++)
    {
        if ( CommandsNames[i] == list[0])
        {
            _command = static_cast<CommandsEnum>(i) ;
            break;
        }
    }

    if ( _command == CommandsEnum::SizeCommandsList)
    {
        //unrecognised
        CommandDescription desc;
        desc.type = CommandType::UNRECOGNISED;
        desc.string = tmp_unrec;
        emit command_ready(desc);
    }
}
