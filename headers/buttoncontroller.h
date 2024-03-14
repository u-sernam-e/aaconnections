#ifndef BUTTONCONTROLLER
#define BUTTONCONTROLLER
#include "interactiondata.h"

// shuffle and guess buttons

class ButtonController
{
    InteractionData* iData;

public:
    void init(InteractionData* idata);
    void reset();
    void update();
    void draw();
};

#endif