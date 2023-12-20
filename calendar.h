#pragma once
#include "month.h"
#include <stack>

class Calendar
{
private:
    std::stack<Month*> months;
    bool goingForward;

public:
    Calendar(Month_e month,
             int year);
    void Input();
    void Print();
private:
    void Next();
    void Previous();
};