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
    CommandDescription desc;

    if ( _command == CommandsEnum::SizeCommandsList)
    {
        //unrecognised
        desc.type = CommandType::UNRECOGNISED;
        desc.string = tmp_unrec;
        emit command_ready(desc);
        return;
    }

    if ( _command == CommandsEnum::Clean)
    {
        //clean
        desc.type = CommandType::CLEAN;
        emit command_ready(desc);
        return;
    }

    if ( _command == CommandsEnum::Help)
    {
        desc.type = CommandType::HELP;
        desc.string = tmp_help;
        emit command_ready(desc);
        return;
    }



    if ( _command == CommandsEnum::Debug)
    {
        // set to debug mode
        desc.type = CommandType::DEBUG_MODE;
        if ( debug_mode_ )
        {
            desc.string = tmp_debug_mode_off;
            debug_mode_ = false;
            desc.status = debug_mode_;
        }else
        {
            desc.string = tmp_debug_mode_on;
            debug_mode_ = true;
            desc.status = debug_mode_;
        }
        emit command_ready(desc);
        return;
    }

    if ( _command == CommandsEnum::Repeat)
    {
        // set to debug mode
        desc.type = CommandType::REPEAT_MODE;
        if ( repeat_mode_ )
        {
            desc.string = tmp_repeat_mode_off;
            repeat_mode_ = false;
            desc.status = repeat_mode_;
        }else
        {
            desc.string = tmp_repeat_mode_on;
            repeat_mode_ = true;
            desc.status = repeat_mode_;
        }
        emit command_ready(desc);
        return;
    }




}
