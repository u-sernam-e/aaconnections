#include "square.h"

Vector2 Square::displayPos()
{
    float betweenAmount{std::min(iData->bd.gt.timeSince(m_moveStartTime)*1.5f, 1.0f)};

    betweenAmount = betweenAmount * betweenAmount * (3 - 2 * betweenAmount); // smoothstep

    return idPos()*(betweenAmount) + m_moveStartPos*(1-betweenAmount);
}

void Square::init(InteractionData* idata, int id, int posId)
{
    iData = idata;

    m_sqrAnim.init(iData);

    m_id = id;
    m_posId = posId;
    m_moveStartPos = getScreenCenter() - size()/2;
    m_moveStartTime = iData->bd.gt.currentTime();
    m_active = true;
    m_selected = false;
    m_moveStartTime = -10000;
}

void Square::updateIData()
{
    iData->sqrs.squares[m_id].selected = m_selected;
}

void Square::update()
{
    if (m_active)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), {displayPos().x, displayPos().y, size().x, size().y}))
        {
            if (m_selected)
                setSelected(false, true);
            else if (iData->sqrs.squaresSelected() < 4)
                setSelected(true, true);
        }
    }

    updateIData();
}

void Square::draw()
{
    m_sqrAnim.draw({displayPos().x, displayPos().y, size().x, size().y}, m_selectedWithMouse);

    DrawRectangleRoundedLines({displayPos().x, displayPos().y, size().x, size().y}, 0.5, 5, 5, WHITE);

    int txtSize{16};
    
    DrawTextEx(iData->bd.fs.get("res/Roboto-Regular.ttf", txtSize), iData->sqrs.squares[m_id].getWord().c_str(), displayPos() + size()/2 - MeasureTextEx(iData->bd.fs.get("res/Roboto-Regular.ttf", txtSize), iData->sqrs.squares[m_id].getWord().c_str(), txtSize, 2)/2, txtSize, 2, (m_selected ? BLACK : WHITE));
}