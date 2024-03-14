#ifndef INTERACTIONDATA
#define INTERACTIONDATA 
#include "basedata.h"
#include "idatastructs.h"

// this struct can be used by classes to talk to each other by setting variables in structs that they can all see

struct InteractionData
{
    BaseData bd;
    SquareIDataContainer sqrs;
    GameConditions gCond;
};

void initID(InteractionData& id);
void updateID(InteractionData& id);
void drawID(InteractionData& id);

#endif