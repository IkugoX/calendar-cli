#include "calendar.h"


int main()
{
    Calendar c(SEP, 2021);
    c.Print();

    while(true)
    {
        // std::cout << "\033[2J\033[H"; 
        c.Input();        
        c.Print();
        std::cout << std::endl;
    }

    return 0;
}