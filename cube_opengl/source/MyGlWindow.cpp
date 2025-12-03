
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
	shaderProgram->initFromFiles("shaders/simple.vert", "shaders/simple.frag");

	/*
	// non dsa 방법
	GLfloat cube_vertices[] =
	{ // attribute 0
		// front
		-1.0, -1.0, 1.0,
		1.0, -1.0, 1.0,
		1.0, 1.0, 1.0,
		-1.0, 1.0, 1.0,
		// back
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0, 1.0, -1.0,
		-1.0, 1.0,-1.0,
	};
	GLfloat cube_colors[] =
	{ // attribute 1
		// front colors
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 1.0, 1.0,
		// back colors
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 1.0, 1.0,
	};
	GLushort cube_elements[] =
	{
		0, 1, 2, 	2, 3, 0, 	1, 5, 6,
		6, 2, 1, 	7, 6, 5, 	5, 4, 7,
		4, 0, 3, 	3, 7, 4, 	4, 5, 1,
		1, 0, 4, 	3, 2, 6, 	6, 7, 3,
	};
	glGenVertexArrays(1, &vaohandle);
	glBindVertexArray(vaohandle);

	GLuint vbo_position;
	glGenBuffers(1, &vbo_position);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_position);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer
	(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);
	glEnableVertexAttribArray(0);


	GLuint vbo_color;
	glGenBuffers(1, &vbo_color);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_colors), cube_colors, GL_STATIC_DRAW);
	glVertexAttribPointer
	(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);
	glEnableVertexAttribArray(1);
	//vbo 후 ibo 생성
	GLuint ibo_cube_elements;
	glGenBuffers(1, &ibo_cube_elements);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_cube_elements);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_elements), cube_elements, GL_STATIC_DRAW);
	*/

	GLfloat cube_vertices[] =
	{ // attribute 0
		// front
		-1.0, -1.0, 1.0,
		1.0, -1.0, 1.0,
		1.0, 1.0, 1.0,
		-1.0, 1.0, 1.0,
		// back
		-1.0, -1.0, -1.0,
		1.0, -1.0, -1.0,
		1.0, 1.0, -1.0,
		-1.0, 1.0,-1.0,
	};
	GLfloat cube_colors[] =
	{ // attribute 1
		// front colors
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 1.0, 1.0,
		// back colors
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		1.0, 1.0, 1.0,
	};
	GLushort cube_elements[] =
	{
		0, 1, 2, 	2, 3, 0, 	1, 5, 6,
		6, 2, 1, 	7, 6, 5, 	5, 4, 7,
		4, 0, 3, 	3, 7, 4, 	4, 5, 1,
		1, 0, 4, 	3, 2, 6, 	6, 7, 3,
	};
	GLuint vbo_position;
	GLuint vbo_color;

	glCreateVertexArrays(1, &vaohandle);
	glCreateBuffers(1, &vbo_position);
	glCreateBuffers(1, &vbo_color);

	glNamedBufferData(vbo_position, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
		glVertexArrayVertexBuffer
		(
			vaohandle,
			0, // binding index, vao
			vbo_position,
			0, // offset
			sizeof(float)*3 // stride
		);
	glNamedBufferData(vbo_color, sizeof(cube_colors), cube_colors, GL_STATIC_DRAW);
		glVertexArrayVertexBuffer
		(
			vaohandle,
			1,
			vbo_color,
			0,
			sizeof(float)*3 // stride
		);
	glVertexArrayAttribBinding(
		vaohandle,
		0, // 속성 번호
		0 // binding index 번호
	);
	glVertexArrayAttribFormat
	(
		vaohandle, 
		0, // 속성 번호
		3, // vertex당 데이터 수
		GL_FLOAT,
		GL_FALSE,
		0 // offset
	);
	glVertexArrayAttribBinding(
		vaohandle,
		0, // 속성 번호
		0 // binding index 번호
	);
	glEnableVertexArrayAttrib(vaohandle, 0);

	glVertexArrayAttribFormat
	(
		vaohandle, 
		1, // 속성 번호
		3, // vertex당 데이터 수
		GL_FLOAT,
		GL_FALSE,
		0 // offset
	);
	glVertexArrayAttribBinding(
		vaohandle,
		1, // 속성 번호
		1 // binding index 번호
	);
	glEnableVertexArrayAttrib(vaohandle, 1);

	GLuint ibo_cube_elements;
	glCreateBuffers(1, &ibo_cube_elements); //Gluint ibo_cube_elements
	glNamedBufferData(ibo_cube_elements, sizeof(cube_elements), cube_elements, GL_STATIC_DRAW);
	glVertexArrayElementBuffer(vaohandle, ibo_cube_elements);
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
	int size;
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE,&size); 
	glDrawElements(GL_TRIANGLES, size / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);

	shaderProgram->disable();
}
