#include "frame.h"
#include <exception>



Frame::Frame(std::function<std::pair<uint8_t, uint8_t> ()> xepr)
{
    knocked_pins = xepr();
    type_this_frame = Usal;
    if(knocked_pins.first > 10 || knocked_pins.second > 10)
    {
        throw std::runtime_error("Playr cant knock down more then 10 pins in one ball");
    }
    //в случае когода первый удар выбил страйк не смотрим на второй а считаем за 0 и отмечаем фрейм страйком
    if((knocked_pins.first + knocked_pins.second) > 10 && knocked_pins.first != 10)
    {
        throw std::runtime_error("Playr cant knock down more then 10 pins in one frame");
    }
    
    if(knocked_pins.first == 10)
    {
        type_this_frame = Strike;
        knocked_pins.second = 0;
    }
    else if(knocked_pins.first + knocked_pins.second == 10)
    {
        type_this_frame = Spare;
    }
    else if(knocked_pins.first + knocked_pins.second == 0)
    {
        type_this_frame = OpenFrame;
    }
    else
    {
        type_this_frame = Usal;
    }
}



