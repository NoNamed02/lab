#version 450

in vec3 fColor;

// frag shader need one more out vec4;
out vec4 fragColor; // pixel's color, why vec4? RGBA values
void main()
{
    fragColor = vec4(fColor, 1.0f);
}