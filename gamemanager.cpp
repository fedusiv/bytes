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
        debug_mode_ = !debug_mode_;
        desc.string = terminal_.debug_mode_string(debug_mode_);
    }

    if ( desc.type == CommandType::REPEAT_MODE)
    {
        repeat_mode_ = !repeat_mode_;
        desc.string = terminal_.repeat_mode_string(repeat_mode_);
    }


    if ( desc.type == CommandType::BOT_ADD )
    {
        process_command_bot_add(desc);
        return;
    }

    emit gui_.append_string(desc.string);
}



void GameManager::process_command_bot_add(CommandDescription desc)
{
    if ( debug_mode_ || desc.debug)
    {
        desc.string = terminal_.bot_string(desc);
        emit gui_.append_string(desc.string);
        emit gui_.change_cell_content_d(QVariant(cell::content_colors[cell::content_names::Bot]), ( (desc.y -1) * 8 + desc.x - 1));
        return;
    }

    if ( repeat_mode_ || desc.repeat )
    {
        // add to main
        qDebug()<<"Send to server";
        desc.string = terminal_.bot_string(desc);
        emit gui_.append_string(desc.string);
        emit gui_.change_cell_content_d(QVariant(cell::content_colors[cell::content_names::Bot]), ( (desc.y -1) * 8 + desc.x - 1));
        return;
    }

    qDebug()<<"Send to server";
}
