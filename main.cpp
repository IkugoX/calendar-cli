#include "calendar.h"


int main()
{
    Calendar c(SEP, 2021);
    c.Print();

    while(true)
    {
        c.Input();        
        c.Print();
    }

    return 0;
}