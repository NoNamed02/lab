#version 450 

// cpu로 부터 받은 속성 0번의 입력을 vec4로 받음
layout(location = 0) in vec4 vertexPosition;
layout(location = 1) in vec3 vertexColor;

out vec3 fColor; // fregment shader로 보냄
void main()
{
    // gl_position = built-in keyword, 클립 좌표계를 받아 들임
    // 나중에 자동으로 gl_position 값을 perspectove division을 해줌

    // 왜 좌표계 변환을 하지 않는가? => 현재 받은 vertexPosition이 클립좌표계로 가정했기 때문
    // 그렇기에 곧바로 넣어도 괜찮음
    // vertex shader에는 반드시 gl_position값을 설정 해야함
    gl_Position = vertexPosition;
    fColor = vertexColor;
}
