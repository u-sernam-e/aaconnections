#ifndef COORDINATOR
#define COORDINATOR 
#include "basedata.h"
#include "interactiondata.h"
#include "squarecontainer.h"
#include "buttoncontroller.h"
#include "grouppanels.h"

// so this file is  the general game coordination,
// controlling what scene the program is in and updating and drawing
// things accordingly

struct GameData
{
    InteractionData iData;
    SquareContainer sqrContainer;
    ButtonController buttController;
    GroupPanels gPanels;
};

void init(GameData& g);
void update(GameData& g);
void draw(GameData& g);

#endif