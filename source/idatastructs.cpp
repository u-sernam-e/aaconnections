#include "idatastructs.h"

std::string SquareIData::getWord()
{
    switch (id)
    {
        case 0:
            return "Mrs. Kress";
        case 1:
            return "Mr. Dineen";
        case 2:
            return "Mr. Decker";
        case 3:
            return "Mr. Levey";

        case 4:
            return "Biology";
        case 5:
            return "US History";
        case 6:
            return "Government";
        case 7:
            return "English\n\nLanguage";

        case 8:
            return "Digital\n\nMedia";
        case 9:
            return "Photography";
        case 10:
            return "Animation";
        case 11:
            return "Coding";

        case 12:
            return "Art";
        case 13:
            return "Music";
        case 14:
            return "Business";
        case 15:
            return "Technology";

        default:
            return "ERROR WORD";
    }
}

std::string groupName(int group)
{
    switch (group)
    {
        case 0:
            return "7th Grade Teachers";
        case 1:
            return "AP Classes";
        case 2:
            return "Taught By Ms. Postilli";
        case 3:
            return "Elective Subjects";
        
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