#include "game.h"
#include <algorithm>
namespace private_grme
{
    std::shared_ptr<Game> game_ptr;
}

std::shared_ptr<Game> Game::get_game(std::initializer_list<Player> playrs_list)
{
    if(!private_grme::game_ptr)
    {
     private_grme::game_ptr = std::shared_ptr<Game>(new Game(playrs_list));
    }
    return private_grme::game_ptr;
}

Game::Game(std::initializer_list<Player> playrs_list) : list_players(playrs_list)
{
}

void Game::start_game()
{
    for(int i = 0; i < 10; i++)
    {
       std::for_each(list_players.begin(), list_players.end(),
           [](const Player& p){p.drop_balls();p.print_status();});
    }
    
     for(auto &p : list_players)
     {
         if(p.type_list_frame() == Frame::TypeFrame::Strike)
         {
             std::cout<<std::endl<<"STRIKEOUT  "<<p.get_name()<<std::endl;
             p.drop_balls();
             p.print_status();
         }
     }
     
}
