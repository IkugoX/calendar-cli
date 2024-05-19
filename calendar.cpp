#include "calendar.h"

Calendar::Calendar(Month_e month,
                   int year)
{
    this->data.open("data.txt");
    if (!this->data.good())
        abort();
    this->months.push(new Month(month, year));
    this->goingForward = true;
    this->isRunning = true;
}

Calendar::~Calendar()
{
    // while (!this->months.empty())
    //     this->months.pop();
    //no clue if i need this

    this->data.close();
}

void Calendar::Input()
{
    char inputText;
    std::cin >> inputText;
    switch (inputText)
    {
    case 'N':
    case 'n':
        this->Next();
        break;
    case 'B':
    case 'b':
        this->Previous();
        break;
    case 'e':
    case 'E':
        this->Update();
        break;
    case 'q':
    case 'Q':
        this->isRunning = false;
        break;
    }
}

void Calendar::Print()
{
    this->months.top()->Print();
    std::cout << "\nb - Back     n - Next     e - Edit     q - Quit\n";
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


#define AVALABLE_COLOURS 6
bool validColour(char& userColour)
{
    //check validity
    char validColours[AVALABLE_COLOURS] = {'r', 'g', 'b', 'c', 'm', 'y'};
    for (size_t i = 0; i < AVALABLE_COLOURS; i++)
    {
        if (validColours[i] == userColour)
            return true;
    }
    std::cout << "ERROR: Invalid colour";
    return false;
}

void Calendar::Update()
{
    int index;
    std::cout << "On what date is the event? "
              << "(1.." << this->months.top()->ReturnNumberOfDays() << ")\n";
    std::cin >> index;
    if (index < 1 || index > this->months.top()->ReturnNumberOfDays())
    {
        std::cout << "ERROR: Invalid date";
        return;
    }

    ColourCode colourForEvent;
    bool isBold;
    //NAME
    std::string eventName;
    std::cout << "What is the event called?\n";
    std::cin >> eventName;
    
    //COLOUR
    std::cout << "Select a colour for the event:\n"
              << "r - Red    g - Green     b - Blue\n"
              << "c - Cyan   m - Magenta   y - Yellow\n";
    char userColour;
    std::cin >> userColour;

    if (!validColour(userColour))
        return;
    
    //COLOUR BOLD
    std::cout << "Do you want the colour to be bold?\n"
              << "y - Yes    n - No\n";
    char userBold;
    std::cin >> userBold;
    if (userBold == 'y')
        isBold = true;
    else if (userBold == 'n')
        isBold = false;
    else
    {
        std::cout << "ERROR: Invalid boldness option";
        return;
    }
    
    switch (userColour)
    {
    case 'r':
        colourForEvent = isBold ? BG_RED : FG_RED;
    break;
    case 'g':
        colourForEvent = isBold ? BG_GREEN : FG_GREEN;
    break;
    case 'b':
        colourForEvent = isBold ? BG_BLUE : FG_BLUE;
    break;
    case 'c':
        colourForEvent = isBold ? BG_CYAN : FG_CYAN;
    break;
    case 'm':
        colourForEvent = isBold ? BG_MAGENTA : FG_MAGENTA;
    break;
    case 'y':
        colourForEvent = isBold ? BG_YELLOW : FG_YELLOW;
    break;
    default:
        std::cout << "ERROR: colour not handled";
        return;
    break;
    }

    this->months.top()->Update(index, eventName, colourForEvent);
    this->Save(this->months.top()->ReturnDay(index));
}

void Calendar::Save(Day &dayToSave)
{
    this->data << this->months.top()->ReturnYear()
               << this->months.top()->ReturnMonth()
               << dayToSave;
}

void Calendar::Load()
{
    
}
