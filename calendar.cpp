#include "calendar.h"

#include <ctype.h>


Calendar::Calendar(Month_e month,
                   int year)
{
    this->months.push(new Month(month, year));
    this->goingForward = true;
}

void Calendar::Input()
{
    char inputText;
    std::cin >> inputText;
    switch (inputText)
    {
    case 'n':
        this->Next();
        break;
    case 'b':
        this->Previous();
        break;
    default:
        break;
    }
    // if ((int)inputText > 0 && (int)inputText < topMonth.ReturnNumberOfDays())
        // topMonth.Update((int)inputText, FG_GREEN);
}


void Calendar::Print()
{
    this->months.top()->Print();
}

void Calendar::Next()
{
    if (this->months.size() == 1)
        this->goingForward = true;
    
    if (this->goingForward)
    {
        if (Month_e(this->months.top()->ReturnMonth()) == DEC)
        {
            this->months.push(new Month(JAN,
                                    this->months.top()->ReturnYear()     + 1));
        }
        else
        {
            this->months.push(new Month(Month_e(this->months.top()->ReturnMonth() + 1),
                                    this->months.top()->ReturnYear()));
        }
    
    }
    else
    {
        this->months.pop();
    }
}

void Calendar::Previous()
{
    if (this->months.size() == 1)
        this->goingForward = false;
    
    if (this->goingForward)
    {
        this->months.pop();
    }
    else
    {
        if (this->months.top()->ReturnMonth() == 1)
            this->months.push(new Month(DEC,
                                    this->months.top()->ReturnYear() - 1));
        else
            this->months.push(new Month(Month_e(this->months.top()->ReturnMonth() - 1),
                                    this->months.top()->ReturnYear()));
    }
}