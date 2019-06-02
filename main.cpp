#include "bowlib/game.h"
#include <initializer_list>
#define LIMIT_NUM_PLAYERS 9
pair_num_pins only_open()
{
    return pair_num_pins{0,0};
}

pair_num_pins only_strike()
{
    return pair_num_pins{10,0};
}

pair_num_pins only_spare()
{
     uint8_t fist_ball = uint8_t(std::rand() % 10);
    uint8_t second_ball = fist_ball == 10 ? 0 : 10 - fist_ball;
    return pair_num_pins{fist_ball,second_ball};
}



// [player1] [player2] ...[time limit in seconds]
int main(int argc, char* argv[])
{

    std::list<Player> geted_players;
    if(argc < 3)
    {
        std::cerr<<"there too less arguments"<<std::endl;
        return 1;
    }
    if(argc > LIMIT_NUM_PLAYERS + 2)
    {
        std::cerr <<"too mach argumets"<<std::endl;
                    return 2;
    }

    std::list<Player> list_playrs;
    for(int i = 1; i <= argc - 2; i++)
    {
        std::string name(argv[i]);
        std::cout << name <<" is ready to play"<<std::endl;
        list_playrs.push_back(Player(name));
    }
    auto game_ptr = Game::get_game(list_playrs);
    try
    {
    game_ptr->set_time_limits(std::stoi(argv[argc - 1]));
    }
    catch(std::invalid_argument)
    {

        std::cout<<argv[argc-1] << "--is invalid as time"<<std::endl;
        return -1;
    }

    game_ptr->play_game(std::string("RESALT.txt"));
    return 0;
    
}
