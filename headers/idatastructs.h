#ifndef IDATASTRUCTS
#define IDATASTRUCTS
#include "rayextended.h"
#include <array>
#include <string>

struct SquareIData
{
    int id;
    bool selected;

    std::string getWord();
};

struct SquareIDataContainer
{
    std::array<SquareIData, 16> squares;

    std::array<int, 4> groupPositions; // -1 means that it has not gotten guessed yet
    
    int squaresSelected(); // counts the squares selected
};

struct GameConditions
{
    int wrongGuesses;
};

std::string groupName(int group);

#endif