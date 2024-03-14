#ifndef GROUPPANELS
#define GROUPPANELS
#include "interactiondata.h"

class GroupPanels
{
    InteractionData* iData;

    std::array<float, 4> m_panelAppearTimes; // time that panels appeared for each group

    std::array<std::string, 4> m_textureNames;

    int m_animFrame;
    float m_lastFrameTime;

public:
    void init(InteractionData* id);
    void update();
    void draw();
};

#endif