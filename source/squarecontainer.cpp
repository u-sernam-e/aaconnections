#include "squarecontainer.h"
#include "button.h"
#include <random>
#include <algorithm>
#include <iostream>

auto shuffleMaker = std::default_random_engine{}; // for shuffleSquares()

void SquareContainer::shuffleSquares() // shuffle squares for when the button is presesed
{
    std::vector<int> ids{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // represents ids
    ids.erase(ids.begin(), ids.begin() + groupsCorrect()*4); // delete the first ones based on how many groups have been guessed correctly
    std::shuffle(ids.begin(), ids.end(), shuffleMaker); // then shuffle
    
    int i{};
    for (auto& s : m_squares)
    {
        if (s.active())
        {
            s.setPosId(ids[i]);
            ++i;
        }
    }
}

void SquareContainer::init(InteractionData* idata)
{
    iData = idata;

    std::vector<int> poop{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // poop
    std::shuffle(poop.begin(), poop.end(), shuffleMaker); // then shuffle
    std::shuffle(poop.begin(), poop.end(), shuffleMaker); // twice

    for (int i{}; i < m_squares.size(); ++i)
    {
        m_squares[i].init(iData, i, poop[i]);
        iData->sqrs.squares[i].id = i;
        iData->sqrs.squares[i].selected = false;
    }

    for (int i{}; i < m_groupPositions.size(); ++i)
    {
        m_groupPositions[i] = -1;
    }
}

void SquareContainer::moveSquaresToCorrectGuessPos(int group)
{
    for (int i{}; i < 4; ++i)
    {
        int squareId{group*4 + i};

        m_squares[squareId].makeInactive(); // do this here so it's done even if it has the correct posid

        if (m_squares[squareId].getPosId() >= (groupsCorrect()-1)*4 && m_squares[squareId].getPosId() < (groupsCorrect()-1)*4 + 4) // checking if the square is already in the correct spot
            continue;

        int desiredSquareId{};

        for (auto& s : m_squares)
        {
            if ((s.getPosId() >= (groupsCorrect()-1)*4 && s.getPosId() < (groupsCorrect()-1)*4 + 4) && // checking if the square has a desired posId and is not in the group
                (s.id() < group*4 || s.id() > group*4 + 3))
                desiredSquareId = s.id();
        }

        int otherSquarePosId{m_squares[desiredSquareId].getPosId()};

        m_squares[desiredSquareId].setPosId(m_squares[squareId].getPosId()); // swap their posids
        m_squares[squareId].setPosId(otherSquarePosId);
    }
}

void SquareContainer::checkGuesses()
{
    std::vector<int> guessIds{}; // all the square ids of selected squares

    for (auto& s : m_squares)
    {
        if (s.selected())
        {
            guessIds.push_back(s.id());
        }
    }

    if (guessIds.size() != 4)
        return;

    int groupNum{m_squares[guessIds[0]].id()/4};
    
    if (m_squares[guessIds[1]].id()/4 == groupNum && m_squares[guessIds[2]].id()/4 == groupNum && m_squares[guessIds[3]].id()/4 == groupNum) // checking if the squares ids are together (this means they are the same group)
    {
        m_groupPositions[m_squares[guessIds[0]].id()/4] = 1;                                    // weird workaround - set it to 1 for the next function because we don't know the correct posId yet
        moveSquaresToCorrectGuessPos(m_squares[guessIds[0]].id()/4);
        m_groupPositions[m_squares[guessIds[0]].id()/4] = m_squares[guessIds[0]].getPosId()/4;  // and then set it to the posId
    }
    else
    {
        ++iData->gCond.wrongGuesses;
    }

    for (auto& s : m_squares)
    {
        s.setSelected(false, false);
    }
}

void SquareContainer::updateIData()
{
    iData->sqrs.groupPositions = m_groupPositions;
}

void SquareContainer::update()
{
    for (auto& s : m_squares)
    {
        s.update();
    }

    if (iData->bd.ui.getElement<Button>("shuffle")->pressed())
    {
        shuffleSquares();
    }

    if (iData->bd.ui.getElement<Button>("submit")->pressed())
    {
        checkGuesses();
    }

    updateIData();
}

void SquareContainer::draw()
{
    for (auto& s : m_squares)
    {
        s.draw();
    }
}