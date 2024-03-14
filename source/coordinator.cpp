#include "coordinator.h"

void reset(GameData& g)
{
}

void init(GameData& g)
{
    initID(g.iData);
    g.sqrContainer.init(&g.iData);
    g.buttController.init(&g.iData);
    g.gPanels.init(&g.iData);
    reset(g);
}

void update(GameData& g)
{
    g.sqrContainer.update();
    g.buttController.update();
    g.gPanels.update();
    updateID(g.iData);
    if (false)
        reset(g);
}

void draw(GameData& g)
{
	ClearBackground(BLACK);

    g.sqrContainer.draw();
    g.buttController.draw();
    g.gPanels.draw();
    drawID(g.iData);
}