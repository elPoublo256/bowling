#include "player.h"
#include <cmath>

Player::Player(const std::string& name, std::function<Frame()> f)
: _name(name), way_make_frame(f){}

Player::Player(const std::string& name, std::function<pair_num_pins()>f)
: _name(name), way_make_frame([f](){return Frame(f);})
{
    std::cout<<"aa"<<std::endl;
}

Player::Player(const Player& copy) : _name(copy._name),
table_all_frames(copy.table_all_frames.str()),
way_make_frame(copy.way_make_frame)
{
  std::cout<<"cc"<<std::endl;
}


Player::~Player(){}

void Player::print_status() const
{   std::cout << std::endl<<std::endl<<std::endl;
    std::cout<<"____________________________________________________"<<std::endl;
    std::cout << _name << " dropped "<<list_frames.size()<<" balls";
    std::cout << "-------------"<<std::endl;
    for(Frame& f : list_frames)
    {
        
        switch(f.get_type_frame())
        {
            case Frame::TypeFrame::Strike :
            {
                std::cout <<" [X]";
                break;
            }
            case Frame::TypeFrame::Usal :
            {
                std::cout << "  ["<<int(f.get_first_balls_pins())
                          << "|"<<int(f.get_second_balls_pins())
                          << f.get_second_balls_pins()
                          <<"]";
                          break;
            }
            case Frame::TypeFrame::OpenFrame :
            {std::cout << " [-]"; break;}
            
            case Frame::TypeFrame::Spare :
            {
              std::cout << " [S]"; break;
            }
                
        }
    }
std::cout <<std::endl; 
std::cout<<"Total:"<<int(totoal_score(list_frames.begin(), list_frames.end()))
<<std::endl;
}


pair_num_pins random_pins()
{
    
    uint8_t fist_ball = uint8_t(std::rand() % 10);
    uint8_t second_ball = fist_ball == 10 ? 0 : (std::rand() % (10 - fist_ball));
    return pair_num_pins{fist_ball,second_ball};
}
