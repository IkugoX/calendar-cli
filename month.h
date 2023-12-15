#pragma once
#include <vector>
#include "day.h"

enum Month_e
    { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

class Month
{
private:
    Month_e month;
    int year;
    
    int startingIndex;
    int numberOfDays;
    std::vector<Day> days;
    
public:
    friend std::ostream& operator<<(std::ostream& os, const Month_e& monthEnum);
    Month(Month_e month,
             int year);
    void Print();
    void Update(int, ColourCode);
    
    int ReturnMonth();
    int ReturnYear();
    int ReturnNumberOfDays();
private:
    void PrintDays();
};