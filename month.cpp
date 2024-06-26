#include <iostream>
#include "month.h"

int dayOffset[12] =
    { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
int daysInAMonth[12] =
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Month::Month(Month_e month,
                   int year)
{
    this->month = month;
    this->year = year;
    
    int q = 1;
    int m = month;
    int k = year % 100;
    int j = year / 100; //Zeller’s Congruence
    this->startingIndex = (1 + 13 * (m + 1) / 5 + k
                            + k / 4 + j / 4 + 5 * j + 5) % 7;


    this->numberOfDays = daysInAMonth[month];
    if (this->month == FEB)
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            this->numberOfDays = 29;

    this->days = {};
    for (size_t i = 1; i <= this->numberOfDays; i++)
        this->days.push_back(Day(i));
}

std::ostream& operator<<(std::ostream& os, const Month_e& monthEnum)
{
   const std::string abbreviation[12] = 
       { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
   return os << abbreviation[monthEnum];
}

void Month::Print()
{
    std::cout << "         " << this->month << "     " << this->year
            //<< "\n~~~~~~~~~~~~~~~~~~~~~\n";
              << "\n---------------------\n"; 
    this->PrintDays();
    std::cout << std::endl;
}

void Month::PrintDays()
{
    for (size_t i = 0; i < this->startingIndex; i++)
        std::cout << "   ";
    
    for (size_t i = 0; i < this->numberOfDays; i++)
    {
        std::cout << this->days[i];
        
        if ((i+1) < 10)
            std::cout << ' ';
        
        if (((i+1) + this->startingIndex) % 7 == 0)
            std::cout << '\n';
    }
}

void Month::Update(int index, std::string eventName, ColourCode colourForEvent)
{
    if (index < 1 || index > this->numberOfDays)
        return;
    
    this->days[index-1].Update(eventName, colourForEvent);
}

int Month::ReturnMonth()
{
    return this->month;
}

int Month::ReturnYear()
{
    return this->year;
}

int Month::ReturnNumberOfDays()
{
    return this->numberOfDays;
}

Day& Month::ReturnDay(int index)
{
    return this->days.at(index);
}