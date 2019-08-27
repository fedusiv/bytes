#include "gamemanager.h"
#include <QDebug>

namespace cell {

enum content_names
{
    Bot
};

QString content_colors[] =
{
  "#82b6e0"
};


}

GameManager::GameManager()
{
    gui_.run();

    connect(&gui_,&GUI::receive_command, &terminal_, &Terminal::parse_command);
    connect(&terminal_, &Terminal::command_ready, this, &GameManager::process_command);
}


void GameManager::process_command(CommandDescription desc)
{
    if( desc.type == CommandType::CLEAN)
    {
        emit gui_.clean_terminal();
        return;
    }

    if ( desc.type == CommandType::DEBUG_MODE)
    {
        debug_mode_ = desc.debug;
    }

    if ( desc.type == CommandType::REPEAT_MODE)
    {
        repeat_mode_ = desc.debug;
    }


    if ( desc.type >= CommandType::BOT_ADD && desc.type <= CommandType::BOT_ADD_REPEAT)
    {
        process_command_bot_add(desc);
        return;
    }

    emit gui_.append_string(desc.string);
}



void GameManager::process_command_bot_add(CommandDescription desc)
{

    if ( desc.type == CommandType::DEBUG_MODE)
    {
        desc.string += terminal_.add_digits_to_string(desc.x, desc.y);
        emit gui_.append_string(desc.string);
        emit gui_.change_cell_content_d(QVariant(cell::content_colors[cell::content_names::Bot]), (desc.x * desc.y - 1));
        return;
    }

    if ( desc.type == CommandType::REPEAT_MODE )
    {
        // add to main
        qDebug()<<"Send to server";


        desc.string += terminal_.add_digits_to_string(desc.x, desc.y);
        emit gui_.append_string(desc.string);
        emit gui_.change_cell_content_d(QVariant(cell::content_colors[cell::content_names::Bot]), (desc.x * desc.y - 1));
        return;
    }

    if ( debug_mode_)
    {
        desc.string += " In debug mode " + terminal_.add_digits_to_string(desc.x, desc.y);
        emit gui_.append_string(desc.string);
        emit gui_.change_cell_content_d(QVariant(cell::content_colors[cell::content_names::Bot]), (desc.x * desc.y - 1));
        return;
    }

    if ( repeat_mode_ )
    {
        // add to main
        qDebug()<<"Send to server";

        desc.string += " And repeat to debug map " + terminal_.add_digits_to_string(desc.x, desc.y);
        emit gui_.append_string(desc.string);
        emit gui_.change_cell_content_d(QVariant(cell::content_colors[cell::content_names::Bot]), (desc.x * desc.y - 1));
        return;
    }

    // add to main
    qDebug()<<"Send to server";
    desc.string += terminal_.add_digits_to_string(desc.x, desc.y);
    emit gui_.append_string(desc.string);
}
