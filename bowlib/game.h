#pragma once

#include "player.h"
#include <list>
#include <memory>

class Game
{
public:
    static std::shared_ptr<Game> get_game(std::initializer_list<Player> playrs_list);
    void start_game();
private:
    Game(std::initializer_list<Player> playrs_list);
    std::list<Player> list_players;
    
};

