#include "day.h"

Day::Day(int index,
        std::string description,
        ColourCode colour)
{
    this->index = index;
    this->description = description;
    this->colour = colour;
}

void Day::Update(std::string eventName, ColourCode& colourForEvent)
{
    this->description = eventName;
    this->colour = colourForEvent;
}


std::ostream& operator<<(std::ostream& os, const Day& obj)
{
    std::cout.width(2);
    
    return os << "\033[" << obj.colour << "m"
            << obj.index << ' '
            << "\033[49m";
}