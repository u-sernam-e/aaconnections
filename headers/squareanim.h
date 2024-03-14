#ifndef SQUAREANIM
#define SQUAREANIM
#include "interactiondata.h"

class SquareAnim // because this is inside Square, 16 different shaders, and 32 rendertextures are loaded on init. this is bad.
{
    InteractionData* iData;
    Shader m_shad;

    unsigned int m_invertedLoc;
    unsigned int m_circLoc;

    RenderTexture m_squareTex;
    RenderTexture m_circTex;

    float m_startTime;

    Vector2 m_mousePos;

public:
    void init(InteractionData* id);
    void start(bool inverted)
    {
        m_mousePos = GetMousePosition();
        m_startTime = iData->bd.gt.currentTime();
        int invInt{inverted};
        SetShaderValue(m_shad, m_invertedLoc, &invInt, SHADER_UNIFORM_INT);
    }
    void draw(Rectangle rect, bool useMousePos);
};

#endif