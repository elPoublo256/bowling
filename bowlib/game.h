#pragma once

#include "player.h"
#include <list>
#include <memory>

class Game
{
public:
    static std::shared_ptr<Game> get_game(std::list<Player> playrs_list);
    void play_game(const std::string& file_name);
    inline void set_time_limits(const int& num_sec)
    {
            time_limits = num_sec;

        }

private:
    Game(std::list<Player> playrs_list);
    std::list<Player> list_players;
    int time_limits;

    
};

