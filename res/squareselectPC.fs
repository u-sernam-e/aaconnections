#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform sampler2D circ;

out vec4 finalColor;

uniform int inverted;

void main()
{
    // Texel color fetching from texture sampler
    vec4 squarePix = texture(texture0, fragTexCoord) * fragColor;
    vec4 circPix = texture(circ, fragTexCoord) * fragColor;

    if (inverted == 0)
    {
        finalColor = squarePix - circPix;
    }
    else
    {
        finalColor = circPix * squarePix;
    }
}