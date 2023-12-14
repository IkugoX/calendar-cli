#include "calendar.h"


int main()
{
    Calendar c(SEP, 2023);

    while(true)
    {
        c.Print();
        c.Input();        
    }

    return 0;
}