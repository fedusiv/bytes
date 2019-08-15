#include "gamemanager.h"

GameManager::GameManager()
{
    gui_.run();

    connect(&gui_,&GUI::receive_command, &terminal_, &Terminal::parse_command);
    connect(&terminal_, &Terminal::command_ready, this, &GameManager::process_command);
}

void GameManager::process_command(CommandDescription desc)
{
    emit gui_.append_string(desc.string);
}
