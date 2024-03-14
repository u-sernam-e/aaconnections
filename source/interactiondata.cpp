#include "interactiondata.h"

void initID(InteractionData& id)
{
	initBD(id.bd);

    id.gCond.wrongGuesses = 0;
}

void updateID(InteractionData& id)
{
	updateBD(id.bd);
}

void drawID(InteractionData& id)
{
	drawBD(id.bd);
}