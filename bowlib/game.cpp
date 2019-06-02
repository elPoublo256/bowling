#include "game.h"
#include <algorithm>
#include <chrono>

#include <fstream>
namespace private_grme
{
    std::shared_ptr<Game> game_ptr;
}

std::shared_ptr<Game> Game::get_game(std::list<Player> playrs_list)
{
    if(!private_grme::game_ptr)
    {
     private_grme::game_ptr = std::shared_ptr<Game>(new Game(playrs_list));
    }
    return private_grme::game_ptr;
}

Game::Game(std::list<Player> playrs_list) : list_players(playrs_list)
{
}


void Game::play_game(const std::string &file_name)
{
    std::cout <<"START GAME FOR "<<time_limits<<"sec"<<std::endl;
    std::ofstream file_out(file_name);
    if(!file_out.is_open()){throw std::runtime_error("cant open output-game file");}

    int num_sec_game = 0;
    auto t_start = std::chrono::system_clock::now();
    for(int i = 0; i < 10; i++)
    {
        if(num_sec_game >= time_limits)
        {
            std::cout << "TIME IS OVER"<<std::endl;
            break;
        }
        std::cout << "GAME TIME : "<<num_sec_game<<"sec"<<std::endl;


       std::for_each(list_players.begin(), list_players.end(),
           []( Player& p){p.drop_balls();p.print_status();});
       auto curent_time = std::chrono::system_clock::now();
       num_sec_game =
               int(std::chrono::duration_cast<std::chrono::seconds>
               (curent_time - t_start).count());
    }

     for(auto &p : list_players)
     {
         if(p.type_last_frame() == Frame::TypeFrame::Strike)
         {
             std::cout<<std::endl<<"STRIKEOUT  "<<p.get_name()<<std::endl;
             p.drop_balls();

         }

        p.print_status(file_out);
     }
     
}
