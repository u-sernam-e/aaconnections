#include "squareanim.h"


void SquareAnim::init(InteractionData* id)
{
    iData = id;
    m_shad = LoadShader(0, "res/squareselect.fs");

    m_invertedLoc = GetShaderLocation(m_shad, "inverted");
    m_circLoc = GetShaderLocation(m_shad, "circ");

    m_squareTex = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
    m_circTex = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());

    m_startTime = -100000000;

    int invInt{0};
    SetShaderValue(m_shad, m_invertedLoc, &invInt, SHADER_UNIFORM_INT);
}


void SquareAnim::draw(Rectangle rect, bool useMousePos)
{
    Vector2 circPos{useMousePos ? m_mousePos : Vector2{rect.x, rect.y} + Vector2{rect.width, rect.height}/2};

    BeginTextureMode(m_squareTex);
    ClearBackground({0, 0, 0, 0});
    DrawRectangleRounded(rect, 0.5, 10, WHITE);
    EndTextureMode();

    BeginTextureMode(m_circTex);
    ClearBackground({0, 0, 0, 0});
    DrawCircleV(circPos, iData->bd.gt.timeSince(m_startTime)*500, WHITE);
    EndTextureMode();

    BeginShaderMode(m_shad);
    SetShaderValueTexture(m_shad, m_circLoc, m_circTex.texture); // important for this to be inside shadermode
    DrawTextureRec(m_squareTex.texture, {0, 0, getScreenSize().x, -getScreenSize().y}, {0, 0}, WHITE);
    EndShaderMode();
}