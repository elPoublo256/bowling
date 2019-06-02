#pragma once
#include <iostream>
#include "frame.h"
#include <string>
#include <list>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <vector>
pair_num_pins keybourd_pins();
class Player
{
private:
  mutable std::stringstream table_all_frames;
   std::string _name;
  mutable std::vector<Frame> list_frames;
   std::function<Frame()> way_make_frame;
   
public:
    Player(const std::string& name, std::function<Frame()> f);
    Player(const std::string& name, 
           std::function<pair_num_pins()>f = keybourd_pins);
    Player(const Player& copy);
    void operator = (const Player& copy);

    virtual ~Player();
    inline std::string get_name() const {return _name;}
    void print_status(std::ostream& s = std::cout) const;
    
    //соверщение игроком броска (вырожение заданное по умолчанию возвращает 
    //фрейм с рандомным числом сбитых кегель
    ///push_back a frame, created by expression way_to_drop to list
     void drop_balls();
     inline Frame::TypeFrame type_last_frame() const
     {return list_frames.front().get_type_frame();}
    
    
};


