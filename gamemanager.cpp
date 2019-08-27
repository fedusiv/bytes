#include "gamemanager.h"

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
        debug_mode_ = desc.status;
    }

    if ( desc.type == CommandType::REPEAT_MODE)
    {
        debug_mode_ = desc.status;
    }


    emit gui_.append_string(desc.string);
}
