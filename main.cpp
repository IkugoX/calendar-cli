#include "calendar.h"


int main()
{
    // Calendar c(SEP, 2021);
    Calendar* c = new Calendar(SEP, 2021);
    c->Print();

    while(c->isRunning)
    {
        // std::cout << "\033[2J\033[H"; 
        c->Input();        
        c->Print();
        std::cout << std::endl;
    }
    
    delete c;
    return 0;
}