#include "bowlib/game.h"
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
int main(int argc, char* argv[])
{
    
    Player p1(std::string("Pavle"), only_spare);
    Player p2(std::string("Ivan"), only_open);
    Player p3(std::string("Gary Moore"), only_strike);
   
    auto geme_ptr = Game::get_game({p1,p2, p3});
    geme_ptr->start_game();
   
    return 0;
    
}
