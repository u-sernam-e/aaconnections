#ifndef SQUARE
#define SQUARE
#include "interactiondata.h"
#include "squareanim.h"

// word squares

class Square
{
    InteractionData* iData;

    SquareAnim m_sqrAnim;

    int m_id;
    int m_posId;

    Vector2 m_moveStartPos;
    float m_moveStartTime; // need to make the squares smovely move to the posIdpos

    bool m_selected;

    bool m_selectedWithMouse;

    bool m_active;

public:
    void init(InteractionData* idata, int id, int posId);
    void reset();
    void update();
    void draw();

    void updateIData();

    Vector2 idPos() { return {20 + 120 * (m_posId%4), 110 + 100 * (m_posId/4)}; }
    Vector2 displayPos();
    Vector2 size() { return {100, 80}; }
    int id() { return m_id; }

    void setPosId(int posId) { 
        m_moveStartPos = idPos();
        m_moveStartTime = iData->bd.gt.currentTime();
        m_posId = posId;
    }
    int getPosId() { return m_posId; }

    void setSelected(bool sel, bool withMouse)
    {
        if (sel != m_selected)
        {
            m_selected = sel;
            m_sqrAnim.start(m_selected);
            m_selectedWithMouse = withMouse;
        }
    }
    bool selected() { return m_selected; }

    void makeInactive() { m_active = false; }
    bool active() { return m_active; }
};

#endif