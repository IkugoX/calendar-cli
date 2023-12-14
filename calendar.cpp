#include "calendar.h"

#include <ctype.h>


Calendar::Calendar(Month_e month,
                   int year)
{
    this->months.push(Month(month, year));
    this->goingForward = false;
}

void Calendar::Input()
{
    if (months.size() == 1)
        this->goingForward = !this->goingForward;
    char inputText;
    std::cin >> inputText;
    switch (inputText)
    {
    case 'n':
        this->Next();
        break;
    case 'p':
        this->Previous();
        break;
    default:
        Month& topMonth = this->months.top();
        if ((int)inputText > 0 && (int)inputText < topMonth.ReturnNumberOfDays())
            topMonth.Update((int)inputText, FG_GREEN);
        topMonth.Update((int)inputText, FG_GREEN);
        break;
    }
}


void Calendar::Print()
{
    Month& topMonth = this->months.top();
    topMonth = months.top();
    topMonth.Print();
}

void Calendar::Next()
{
    Month& topMonth = this->months.top();
    topMonth = months.top();
    if (this->goingForward)
    {
        if (topMonth.ReturnMonth() == 12)
            this->months.push(Month(JAN,
                                    topMonth.ReturnYear() + 1));
        else
            this->months.push(Month(Month_e(topMonth.ReturnMonth() + 1),
                                    topMonth.ReturnYear()));
    }
    else
    {
        if (topMonth.ReturnMonth() == 1)
            this->months.push(Month(DEC,
                                    topMonth.ReturnYear() - 1));
        else
            this->months.push(Month(Month_e(topMonth.ReturnMonth() - 1),
                                    topMonth.ReturnYear()));
    }
}

void Calendar::Previous()
{
    this->months.pop();
}