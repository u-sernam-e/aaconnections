#version 100

precision mediump float;

// Input vertex attributes (from vertex shader)
varying vec2 fragTexCoord;

// Input uniform values
uniform sampler2D texture0;
uniform sampler2D circ;

uniform int inverted;

void main()
{
    // Texel color fetching from texture sampler
    vec4 squarePix = texture2D(texture0, fragTexCoord);
    vec4 circPix = texture2D(circ, fragTexCoord);

    if (inverted == 0)
    {
        gl_FragColor = squarePix - circPix;
    }
    else
    {
        gl_FragColor = circPix * squarePix;
    }
}