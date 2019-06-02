#pragma once
#include <stdint.h>
#include <utility>
#include <functional>

typedef typename std::pair<uint8_t, uint8_t> pair_num_pins; 
class Frame 
{
public:
    Frame(std::function<pair_num_pins(void)> xepr);
    //для быстрой проверки является ли Фрейм страйком или ...
    enum TypeFrame
    {
         Strike, //10 pins in 1st ball
         OpenFrame, // 0 pins in 2 balls
         Spare, // 10 bals in 2 balls
         Usal
    };
    uint8_t score() const;
private:
    TypeFrame type_this_frame;
    pair_num_pins  knocked_pins;
public:
     
    inline TypeFrame get_type_frame() const {return type_this_frame;}
    
    inline uint8_t get_knoked_pins() const 
    {return knocked_pins.first + knocked_pins.second;}
    
    inline uint8_t get_first_balls_pins() {return knocked_pins.first;}
    inline uint8_t get_second_balls_pins() {return knocked_pins.second;}
};



template <class FramesIterator>
uint16_t totoal_score(FramesIterator first, FramesIterator last)
{
    uint16_t result = 0;
    for(auto it = first; it != last; it++)
    {
        switch(it->get_type_frame())
        {
            
            case Frame::TypeFrame::Strike :
            {
             result += it->get_knoked_pins();
             if(it + 1 < last)
             {
               result += (it + 1)->get_knoked_pins();
                 if(it + 2 < last)
                 {
                    result += (it + 2)->get_knoked_pins();
                 }
             }
              break;
            }
            
            case Frame::TypeFrame::Spare :
            {
             result += it->get_knoked_pins();
             if(it + 1 < last) { result += (it + 1)->get_knoked_pins();}
             break;
            }

        case Frame::Usal :
        {
            result += it->get_knoked_pins();
            break;

        }
            default:
            {
                  result += it->get_knoked_pins();
                  break;
            
            }
        }
        
    
    }
    return result;
}




	

