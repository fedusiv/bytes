#include "terminal.h"
#include <QDebug>
Terminal::Terminal()
{

}

QString Terminal::bot_string(CommandDescription desc)
{
    if ( desc.debug )
    {
        return  tmp_bot_add_d + add_digits_to_string(desc.x, desc.y);
    }

    if ( desc.repeat )
    {
        return  tmp_bot_add_r + add_digits_to_string(desc.x, desc.y);
    }

    return desc.string + add_digits_to_string(desc.x, desc.y);


}

QString Terminal::debug_mode_string(bool mode)
{
    if ( mode )
    {
        return  tmp_debug_mode_on;
    }
    return  tmp_debug_mode_off;
}

QString Terminal::repeat_mode_string(bool mode)
{
    if ( mode )
    {
        return  tmp_repeat_mode_on;
    }
    return  tmp_repeat_mode_off;
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
    command_desc_clear(&desc);

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
        desc.debug = true;
        emit command_ready(desc);
        return;
    }

    if ( _command == CommandsEnum::Repeat)
    {
        // set to repeat mode
        desc.type = CommandType::REPEAT_MODE;
        desc.repeat = true;
        emit command_ready(desc);
        return;
    }


    if ( _command == CommandsEnum::Bot)
    {
        // Bot
        list.removeFirst();
        parse_command_bot(list);
        return;
    }


}

QString Terminal::add_digits_to_string(int x, int y)
{
    return "  at x: " + QString::number(x) + " y: " + QString::number(y);
}

void Terminal::command_desc_clear(CommandDescription *desc)
{
    desc->x = 0;
    desc->y = 0;
    desc->debug = false;
    desc->repeat = false;
}

void Terminal::parse_command_bot(QStringList list)
{
    bool digit_part = false;
    uint8_t digit_counter = 0;
    CommandDescription desc;
    command_desc_clear(&desc);
    CommandsOptionsEnum cmd = CommandsOptionsEnum::SizeOptionsEnum;
    for ( QString c : list)
    {
        if ( digit_part)
        {
            digit_counter++;
            int axis = c.toInt();
            if ( axis >= 1 && axis <= MAP_SIZE )
            {
                if ( digit_counter == 1)
                {
                    desc.x = axis;
                }
                if ( digit_counter == 2)
                {
                    desc.y = axis;
                    digit_part = false;
                }
            }else
            {
                desc.type = CommandType::UNRECOGNISED;
                desc.string = tmp_unrec_digit + " ( " + c + " ) ?";
                emit command_ready(desc);
                return;
            }

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
            desc.string = tmp_unrec + " ( " + c + " ) ?";
            emit command_ready(desc);
            return;
        }


        if ( pos == CommandsOptionsEnum::Add)
        {
            digit_part = true;
            desc.type = CommandType::BOT_ADD;
            desc.string = tmp_bot_add;
        }

        if ( pos == CommandsOptionsEnum::Debug_option)
        {
            desc.debug = true;
        }

        if ( pos == CommandsOptionsEnum::Repeat_option)
        {
            desc.repeat = true;
        }

    }
    emit command_ready(desc);


}
