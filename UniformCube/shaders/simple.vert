#version 450 

layout(location=0) in vec3 VertexPosition;
layout(location=1) in vec3 v_color;
uniform mat4 mvp;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 f_color; // fregment shader로 보냄

void main()
{
    // gl_Position = projection * view * model * vec4(coord3d, 1.0);
    gl_Position = mvp * vec4(VertexPosition,1.0);
    f_color = v_color;
}
