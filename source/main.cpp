#include "coordinator.h" 
#include "rayextended.h" 
#include <vector>
#if defined(PLATFORM_WEB)
	#include <emscripten/emscripten.h>
#endif
GameData G;

void updateDrawFrame()
{
	//UPDATE
	update(G);
	//DRAW
	BeginDrawing();
	draw(G);
	EndDrawing();
}

int main()
{
	InitWindow(500, 600, "AAConnections");
    InitAudioDevice();
	init(G);

#if defined(PLATFORM_WEB)
	emscripten_set_main_loop(updateDrawFrame, 0, 1);
#else
	while (!WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
	{
		updateDrawFrame();
	}
#endif
	return 0;
}