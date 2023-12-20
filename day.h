#pragma once
#include <string>
#include <iostream>

enum ColourCode
{
    FG_RED      = 31,
    FG_GREEN    = 32,
    FG_YELLOW   = 33,
    FG_BLUE     = 34,
    FG_MAGENTA  = 35,
    FG_CYAN     = 36,
    FG_DEFAULT  = 39,
    BG_RED      = 41,
    BG_GREEN    = 42,
    BG_YELLOW   = 43,
    BG_BLUE     = 44,
    BG_MAGENTA  = 45,
    BG_CYAN     = 46,
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
        ColourCode colour = FG_DEFAULT);
        
    void Update(std::string, ColourCode&);

    friend std::ostream& operator<<(std::ostream& os, const Day& obj);
};