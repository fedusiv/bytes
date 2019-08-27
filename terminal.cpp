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
            desc.debug = debug_mode_;
        }else
        {
            desc.string = tmp_debug_mode_on;
            debug_mode_ = true;
            desc.debug = debug_mode_;
        }
        emit command_ready(desc);
        return;
    }

    if ( _command == CommandsEnum::Repeat)
    {
        // set to repeat mode
        desc.type = CommandType::REPEAT_MODE;
        if ( repeat_mode_ )
        {
            desc.string = tmp_repeat_mode_off;
            repeat_mode_ = false;
            desc.repeat = repeat_mode_;
        }else
        {
            desc.string = tmp_repeat_mode_on;
            repeat_mode_ = true;
            desc.repeat = repeat_mode_;
        }
        emit command_ready(desc);
        return;
    }


    if ( _command == CommandsEnum::Bot)
    {
        list.removeFirst();
        parse_command_bot(list);
        return;
    }


}

QString Terminal::add_digits_to_string(int x, int y)
{
    return "  at x: " + QString::number(x) + " y: " + QString::number(y);
}

void Terminal::parse_command_bot(QStringList list)
{
    bool digit_part = false;
    CommandDescription desc;
    CommandsOptionsEnum cmd = CommandsOptionsEnum::SizeOptionsEnum;
    for ( QString c : list)
    {
        if ( digit_part)
        {
            continue;
        }

        int pos = CommandsOptions.indexOf(c);
        if ( pos != -1)
        {
            cmd = static_cast<CommandsOptionsEnum>(pos);
        }
        else
        {
            // unrecognised
            desc.type = CommandType::UNRECOGNISED;
            desc.string = tmp_unrec;
            emit command_ready(desc);
            return;
        }



    }


}
