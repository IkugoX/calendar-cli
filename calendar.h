#pragma once
#include "month.h"
#include <stack>
#include <fstream>

class Calendar
{
private:
    std::stack<Month*> months;
    bool goingForward;
    std::fstream data;

public:
    bool isRunning;
    Calendar(Month_e month,
             int year);
    ~Calendar();
    void Input();
    void Print();
private:
    void Next();
    void Previous();
    void Update();

    void Save(Day &);
    void Load();
};