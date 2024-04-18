#include "buttoncontroller.h"
#include "button.h"

void ButtonController::init(InteractionData* idata)
{
    iData = idata;

    iData->bd.ui.addElements<Button>({
        Button{getScreenCenter() + Vector2{-130, 215}, {100, 30}, WHITE, GRAY, LIGHTGRAY, "Submit", WHITE, false, false, false, idata->bd.ts.get(""), false, &idata->bd.fs, "res/Roboto-Regular.ttf"},
        Button{getScreenCenter() + Vector2{20, 215}, {100, 30}, WHITE, GRAY, LIGHTGRAY, "Shuffle", WHITE, false, false, false, idata->bd.ts.get(""), false, &idata->bd.fs, "res/Roboto-Regular.ttf"}},
    {"submit", "shuffle"});
}

void ButtonController::update()
{

}

void ButtonController::draw()
{
    int txtSize{43};
    float xPosA{getScreenCenter().x - MeasureTextEx(iData->bd.fs.get("res/Roboto-Bold.ttf", txtSize), "The AAConnections Vol. 2", txtSize, 2).x/2}; // I guess this can be there
    DrawTextEx(iData->bd.fs.get("res/Roboto-Bold.ttf", txtSize), "The AAConnections Vol. 2", {xPosA, 35}, txtSize, 2, WHITE);

    const char* text{TextFormat("Wrong Guesses: %i", iData->gCond.wrongGuesses)};
    float xPosB{getScreenCenter().x - MeasureTextEx(iData->bd.fs.get("res/Roboto-Regular.ttf", 25), text, 25, 2).x/2};
    DrawTextEx(iData->bd.fs.get("res/Roboto-Regular.ttf", 25), text, {xPosB, 560}, 25, 2, WHITE);
}