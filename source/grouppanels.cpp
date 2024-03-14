#include "grouppanels.h"
#include <algorithm>

void GroupPanels::init(InteractionData* id)
{
    iData = id;

    for (auto& t : m_panelAppearTimes)
    {
        t = -1;
    }

    m_textureNames[0] = "res/bluepanel.png";
    m_textureNames[1] = "res/goldpanel.png";
    m_textureNames[2] = "res/shinybluepanel.png";
    m_textureNames[3] = "res/shinygoldpanel.png";

    m_animFrame = 0;
    m_lastFrameTime = 0;
}

void GroupPanels::update()
{
    for (int i{}; i < m_panelAppearTimes.size(); ++i)
    {
        float& t{m_panelAppearTimes[i]};

        if (t == -1 && iData->sqrs.groupPositions[i] != -1) // because they are inited at -1
        {
            t = iData->bd.gt.currentTime();
        }
    }
    if (iData->bd.gt.timeSince(m_lastFrameTime) > 0.2)
    {
        m_animFrame = (m_animFrame+1)%3;
        m_lastFrameTime = iData->bd.gt.currentTime();
    }
}

void replace_first( // NOT STOLEN FROM STACKOVERFLOW I SWEAR
    std::string& s,
    std::string const& toReplace,
    std::string const& replaceWith
) {
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos) return;
    s.replace(pos, toReplace.length(), replaceWith);
}

void GroupPanels::draw()
{
    for (int i{}; i < m_panelAppearTimes.size(); ++i)
    {
        float& panelT{m_panelAppearTimes[i]};

        if (panelT == -1)
            continue;

        Texture tx{iData->bd.ts.get(m_textureNames[i])};

        float t{std::clamp(iData->bd.gt.timeSince(panelT)*2.0f - 1.5f, 0.0f, 1.0f)}; // time
        t = t * t * (3 - 2 * t); // smoothstep

        if (i < 2) // not shiny
            DrawTexturePro(tx, {0, 0, tx.width, tx.height}, {10, 155 + 100*iData->sqrs.groupPositions[i] - 50*t, tx.width, tx.height*t}, {0, 0}, 0, {255, 255, 255, 255});
        else // shiny
            DrawTexturePro(tx, {0, m_animFrame * tx.height/3, tx.width, tx.height/3}, {10, 155 + 100*iData->sqrs.groupPositions[i] - 50*t, tx.width, (tx.height/3)*t}, {0, 0}, 0, {255, 255, 255, 255});


        float xPosA{getScreenSize().x/2 - MeasureTextEx(iData->bd.fs.get("res/Roboto-Regular.ttf", 40), groupName(i).c_str(), 40, 2).x/2};
        DrawTextEx(iData->bd.fs.get("res/Roboto-Regular.ttf", 40), groupName(i).c_str(), {xPosA, 115 + 100*iData->sqrs.groupPositions[i]}, 40, 2, {0, 0, 0, t*255});


        std::string text{iData->sqrs.squares[i*4].getWord() + ", " + iData->sqrs.squares[i*4 + 1].getWord() + ", " + iData->sqrs.squares[i*4 + 2].getWord() + ", " + iData->sqrs.squares[i*4 + 3].getWord()};

        replace_first(text, "\n\n", " "); replace_first(text, "\n\n", " "); replace_first(text, "\n\n", " "); replace_first(text, "\n\n", " "); //lol whats a loop

        float xPosB{getScreenSize().x/2 - MeasureTextEx(iData->bd.fs.get("res/Roboto-Regular.ttf", 20), text.c_str(), 20, 2).x/2};
        DrawTextEx(iData->bd.fs.get("res/Roboto-Regular.ttf", 20), text.c_str(), {xPosB, 165 + 100*iData->sqrs.groupPositions[i]}, 20, 2, {0, 0, 0, t*255});

    }
}