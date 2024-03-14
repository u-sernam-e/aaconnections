#ifndef SQUARECONTAINER
#define SQUARECONTAINER
#include "interactiondata.h"
#include "square.h"
#include <array>

class SquareContainer
{
    InteractionData* iData;

    std::array<Square, 16> m_squares;

    std::array<int, 4> m_groupPositions; // if a group of words is correct, this is true for that group

    void shuffleSquares();
    void moveSquaresToCorrectGuessPos(int group);
    void checkGuesses();

    int groupsCorrect()
    {
        int output{};
        for (int i{}; i < 4; ++i)
        {
            if (m_groupPositions[i] != -1)
                ++output;
        }
        return output;
    }
public:
    void init(InteractionData* idata);
    void reset();
    void update();
    void draw();

    void updateIData();
};

#endif