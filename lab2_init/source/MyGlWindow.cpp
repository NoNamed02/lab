
#define GLM_ENABLE_EXPERIMENTAL 
#include "MyGlWindow.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

MyGlWindow::MyGlWindow(int w, int h)
{
	m_width = w;
	m_height = h;

	setupBuffer();	
}

void MyGlWindow::setupBuffer()
{
	shaderProgram = std::make_unique<ShaderProgram>();
	
	//load shaders : set vertex shader, fragment shader
	shaderProgram->initFromFiles("shaders/simple.vert", "shaders/simple.frag");
	// 삼각형 정보 배열에 저장
	// 속성 num = 0
	//const float vertexPosition[] = 
	//{
	//	-0.2f, 0.0f, 0.0f, 1.0f,
	//	 0.0f, 0.4f, 0.0f, 1.0f,
	//	 0.2f, 0.0f, 0.0f, 1.0f,
	//};
	// const float vertexPosition[] =
	// {
	// 	 -0.2f, -0.2f, 0.0f, 1.0f, // 0
	// 	 -0.2f,  0.2f, 0.0f, 1.0f, // 1
	// 	  0.2f, -0.2f, 0.0f, 1.0f, // 2

	// 	//   0.2f, -0.2f, 0.0f, 1.0f, // 1
	// 	//   0.2f,  0.2f, 0.0f, 1.0f, // 2
	// 	  0.2f,  0.2f, 0.0f, 1.0f, // 3
	// };
	// 삼각형 색상 저장
	// 속성 num = 1
	//const float vertexColor[] = 
	//{
	//	1.0f, 0.0f, 0.0f,
	//	0.0f, 1.0f, 0.0f,
	//	0.0f, 0.0f, 1.0f
	//};
	// const float vertexColor[] =
	// {
	// 	1.0f, 0.0f, 0.0f,
	// 	0.0f, 1.0f, 0.0f,
	// 	0.0f, 0.0f, 1.0f,
	// 	// 0.0f, 0.0f, 1.0f,
	// 	// 1.0f, 0.0f, 0.0f,
	// 	1.0f, 0.0f, 0.0f,
	// };
	// 삼각형에 대한 장보를 gpu에 전달
	// 삼각형이 가진 속성정보 : 위치, 색상
	/*
	
	1. VAO 생성
	2. VBO 생성
	3. 

	*/
	// VAO 생성(vertex Array Object)
	
	// 컨테이넌 생성
	// glGenVertexArrays(1, &vaohandle);
	// // 여러개의 vao중에 무엇을 사용할 것인가 선택
	// glBindVertexArray(vaohandle); // bind = activate, 해당 장소에 뭔가 작업을 할 것 이다
	
	// GLuint vbo_position;
	// glGenBuffers(1, &vbo_position); // vertex 위치 정보를 저장하기 위한 vbo
	// glBindBuffer(GL_ARRAY_BUFFER, vbo_position);

	// // 데이터를 메인 메모레 -> GPU메모리로 보내고 할당 : 마지막 : usage
	// glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPosition), &vertexPosition, GL_STATIC_DRAW);

	// glVertexAttribPointer(
	// 	0, // 속성 번호
	// 	4, // 데이터 갯수
	// 	GL_FLOAT, // 데이터 타입
	// 	GL_FALSE, // 정규화 여부
	// 	0, // stride
	// 	0 // offset
	// );
	// 속성 enable
	// glEnableVertexAttribArray(0); // 속성번호

	// GLuint vbo_color;
	// glGenBuffers(1, &vbo_color);
	// glBindBuffer(GL_ARRAY_BUFFER, vbo_color);

	// glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColor), &vertexColor, GL_STATIC_DRAW);

	// glVertexAttribPointer(
	// 	1, // 속성 번호
	// 	3, // 데이터 갯수
	// 	GL_FLOAT, // 데이터 타입
	// 	GL_FALSE, // 정규화 여부
	// 	0, // stride
	// 	0 // offset
	// );
	// glEnableVertexAttribArray(1); // 속성번호

	// glBindVertexArray(0); // 현재 사용중인 vao unbound


	/* non dsa 방법 = none dirext state access 방법
	const float vertices[] =
	{	// 위치, 컬러 섞어서 사용, interleave 방법
		 -0.2f,  0.0f,  0.0f,  1.0f,		1.0f, 0.0f, 0.0f, // v0
		  0.0f,  0.4f,  0.0f,  1.0f,		0.0f, 1.0f, 0.0f, // v1
		  0.2f,  0.0f,  0.0f,  1.0f,		0.0f, 0.0f, 1.0f, // v2
	};
	glGenVertexArrays(1, &vaohandle); // 컨테이너 생성
	glBindVertexArray(vaohandle); // 바인딩

	GLuint vbo_vertex; // vbo 생성
	glGenBuffers(1, &vbo_vertex);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertex); // vbo 바인딩 = activate

	// cpu 정보를 gpu로 가져옴, 이후 gpu에게 해석 방법 알려줘야함
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
		glVertexAttribPointer // 위치 처리
		(
			0, // 속성 번호
			4, // 버텍스당 데이터 갯수
			GL_FLOAT,
			GL_FALSE,
			sizeof(float)*7, // 위치 이후 얼마 이후 다시 위치가 시작하는가? = stride
			(void*)0 // offset = 얼마 후에 데이터가 시작되는가
		);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer // 컬러 처리
		(
			1, // 속성 번호
			3, // 버텍스당 데이터 갯수
			GL_FLOAT,
			GL_FALSE,
			sizeof(float)*7, // 컬러 이후 얼마 이후 다시 컬러가 시작하는가? = stride
			(void*)(sizeof(float)*4) // offset = 얼마 후에 데이터가 시작되는가
		);
		glEnableVertexAttribArray(1);

	glBindVertexArray(0); // 언바인딩
	*/


	// //DSA 방법 : 함수 명이 달라짐
	// /*
	// 	1. vao 생성
	// */
	// const float vertexPosition[] = 
	// {
	// 	-0.2f, 0.0f, 0.0f, 1.0f,
	// 	 0.0f, 0.4f, 0.0f, 1.0f,
	// 	 0.2f, 0.0f, 0.0f, 1.0f,
	// };
	// const float vertexColor[] = 
	// {
	// 	1.0f, 0.0f, 0.0f,
	// 	0.0f, 1.0f, 0.0f,
	// 	0.0f, 0.0f, 1.0f
	// };
	// // 1. vao 생성
	// GLuint vbo_position;
	// GLuint vbo_color;
	// // gl_create = dsa 방법
	// glCreateVertexArrays(1, &vaohandle);
	// glCreateBuffers(1, &vbo_position);
	// glCreateBuffers(1, &vbo_color);

	// // 2. vbo 생성
	// // position 처리
	// // cpu -> gpu 할당
	// 	glNamedBufferData(vbo_position, sizeof(vertexPosition), vertexPosition, GL_STATIC_DRAW);
	// // gpu에게 해석 방법 알려줌
	// 	glVertexArrayVertexBuffer
	// 	(
	// 		vaohandle,
	// 		0, // binding index, vao
	// 		vbo_position,
	// 		0, // offset
	// 		sizeof(float)*4 // stride
	// 	);

	// // color 처리
	// 	glNamedBufferData(vbo_color, sizeof(vertexColor), vertexColor, GL_STATIC_DRAW);
	// 	glVertexArrayVertexBuffer
	// 	(
	// 		vaohandle,
	// 		1,
	// 		vbo_color,
	// 		0,
	// 		sizeof(float)*3
	// 	);

	// glVertexArrayAttribFormat
	// (
	// 	vaohandle, 
	// 	0, // 속성 번호
	// 	4, // vertex당 데이터 수
	// 	GL_FLOAT,
	// 	GL_FALSE,
	// 	0 // offset
	// );
	// glVertexArrayAttribBinding(
	// 	vaohandle,
	// 	0, // 속성 번호
	// 	0 // binding index 번호
	// );
	// glEnableVertexArrayAttrib(vaohandle, 0); // 0번 속성 enable


	// glVertexArrayAttribFormat
	// (
	// 	vaohandle, 
	// 	1, // 속성 번호
	// 	3, // vertex당 데이터 수
	// 	GL_FLOAT,
	// 	GL_FALSE,
	// 	0 // offset
	// );
	// glVertexArrayAttribBinding(
	// 	vaohandle,
	// 	1, // 속성 번호
	// 	1 // binding index 번호
	// );
	// glEnableVertexArrayAttrib(vaohandle, 1); // 1번 속성 enable

	// dsa interleave
	const float vertices[] =
	{	// 위치, 컬러 섞어서 사용, interleave 방법
		 -0.2f,  0.0f,  0.0f,  1.0f,		1.0f, 0.0f, 0.0f, // v0
		  0.0f,  0.4f,  0.0f,  1.0f,		0.0f, 1.0f, 0.0f, // v1
		  0.2f,  0.0f,  0.0f,  1.0f,		0.0f, 0.0f, 1.0f, // v2
	};
	/*----------------시험, 어디에 뭐가 있는가??----------------*/
	GLuint vbo_vertex;
	glCreateVertexArrays(1, &vaohandle);
	glCreateBuffers(1, &vbo_vertex);

	glNamedBufferData(vbo_vertex, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexArrayVertexBuffer(vaohandle, 0, vbo_vertex, 0, sizeof(float)*7);

	glVertexArrayAttribFormat(vaohandle, 0, 4, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribBinding(vaohandle, 0, 0); // 속성번호 = 0, binding index = 0
	glEnableVertexArrayAttrib(vaohandle, 0);
	
	glVertexArrayAttribFormat(vaohandle, 1, 3, GL_FLOAT, GL_FALSE, (sizeof(float)*4));
	glVertexArrayAttribBinding(vaohandle, 1, 0); // 속성번호 = 1, binding index = 0
	glEnableVertexArrayAttrib(vaohandle, 1);
	/*----------------시험----------------*/
}

void MyGlWindow::draw(void)
{
	// set background color
	glClearColor(0.2f, 0.2f, 0.2f, 1);
	// set delete buffer, 레스터라제이션 할때 두 개의 버퍼 color, depth
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 1. shader use
	shaderProgram->use();
	// 2. vao binding
	glBindVertexArray(vaohandle);
	// 3. cal draw func
	glDrawArrays(GL_TRIANGLES, 0, 6);
	
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); // => 자동으로 반복시켜줌
	// primitive = gl_triangles같은 형태들, point, line, triangle 이렇게 3개 있음
	// v0 - v1 - v2 // v1 - v2 - v3 일시 자동으로 중앙 1, 2를 복사해줌


	shaderProgram->disable();
}
