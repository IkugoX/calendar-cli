#pragma once
#include <string>
#include <iostream>

enum ColourCode
{
    FG_RED      = 31,
    FG_GREEN    = 32,
    FG_BLUE     = 34,
    FG_DEFAULT  = 39,
    BG_RED      = 41,
    BG_GREEN    = 42,
    BG_BLUE     = 44,
    BG_DEFAULT  = 49
};

class Day
{
private:
    int index;
    std::string description;
    ColourCode colour;

public:
    Day(int index = 255,
        std::string description = "N/A",
        ColourCode colour = BG_DEFAULT);
        
    void Update(ColourCode&);

    friend std::ostream& operator<<(std::ostream& os, const Day& obj);
};