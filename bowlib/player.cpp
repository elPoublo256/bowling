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
//  std::cout<<"cc"<<std::endl;
}

void Player::operator =(const Player& copy)
{
    _name = copy._name;
   table_all_frames << copy.table_all_frames.str();
   way_make_frame = copy.way_make_frame;
}

Player::~Player(){}

void Player::print_status(std::ostream &s) const
{

    s << _name <<':'<<std::endl;
    s << table_all_frames.str()<<std::endl;
    s << "Total:"<< totoal_score(list_frames.begin(), list_frames.end()) << std::endl;
    s << std::endl<<std::endl<<std::endl;
}

void Player::drop_balls()
{
    Frame new_frame(way_make_frame());
    switch (new_frame.get_type_frame()) {
    case Frame::TypeFrame::Strike :
    {
        table_all_frames << "[X]";
        break;
    }
    case Frame::TypeFrame::OpenFrame :
        {
          table_all_frames << "[-]";
          break;
        }
    case Frame::TypeFrame::Spare :
        {
          table_all_frames << "[S]";
          break;
        }
    case Frame::TypeFrame::Usal :
        {
          table_all_frames << "["<<
                           int(new_frame.get_first_balls_pins()) <<
                              "|"<<
                              int(new_frame.get_second_balls_pins())
                           <<"]";
          break;
        }
    default:
        throw std::runtime_error("undefined type of frame");
    }
    list_frames.push_back(new_frame);
}

pair_num_pins keybourd_pins()
{
    int first_ball, second_ball;
    do
    {
    std::cout << "print number pins in first ball"<<std::endl;
    std::cin >> first_ball;
    std::cout << "print number pins in second ball"<<std::endl;
    std::cin >> second_ball;
    if(first_ball + second_ball <= 10)
    {
        if(first_ball >=0 && second_ball >=0)
        {
            break;
        }
        else
        {
            std::cout << "all number pins shoul be positive"<<std::endl;
        }
    }
    else
    {
        std::cout << "summ number of pins in frame shold be no more 10"<<std::endl;
    }
    std::cout << "try again"<<std::endl;
    }
    while(true);
    return pair_num_pins{uint8_t(first_ball),uint8_t(second_ball)};
}
