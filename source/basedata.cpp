#include "basedata.h"
#include <iostream>

void initBD(BaseData& b)
{
	b.ts.init({"res/error.png", "res/1px.png", "res/bluepanel.png", "res/goldpanel.png", "res/shinybluepanel.png", "res/shinygoldpanel.png"});
    b.fs.init({"res/Roboto-Regular.ttf", "res/Roboto-Bold.ttf"});
    b.ss.init({}); 
    b.ms.init({}); 

    b.ui.init();
    b.gt.init();
}

void updateBD(BaseData& b)
{
    b.ui.update();
    b.gt.update();
}

void drawBD(BaseData& b)
{
    b.ui.draw();
}