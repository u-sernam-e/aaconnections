#include "idatastructs.h"

std::string SquareIData::getWord()
{
    switch (id)
    {
        case 0:
            return "Bonfire";
        case 1:
            return "Glow";
        case 2:
            return "Halloween";
        case 3:
            return "Snowball";

        case 4:
            return "Pep\n\nRally";
        case 5:
            return "Bumpa\n\nPalooza";
        case 6:
            return "Team\n\nTrivia";
        case 7:
            return "Food\n\nDrive";

        case 8:
            return "Turner";
        case 9:
            return "Decker";
        case 10:
            return "Donlon";
        case 11:
            return "Cook";

        case 12:
            return "Dineen";
        case 13:
            return "Kress";
        case 14:
            return "Bensley";
        case 15:
            return "Carretto";

        default:
            return "-=!ERROR!=-";
    }
}

std::string groupName(int group)
{
    switch (group)
    {
        case 0:
            return "Dances";
        case 1:
            return "Student Government Events";
        case 2:
            return "Teachers Who Coach";
        case 3:
            return "Grades 9-12 Class Advisors";
        
        default:
            return "ERROR GROUP NAME";
    }
}

int SquareIDataContainer::squaresSelected()
{
    int output{};
    for (auto& s : squares)
    {
        if (s.selected)
            ++output;
    }
    return output;
} 