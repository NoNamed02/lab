#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL 
#include "MyGlWindow.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

ColorCube::ColorCube()
{
	setup();
}

void ColorCube::setup()
{
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
    glCreateVertexArrays(1, &vaohandle);
    glCreateBuffers(1, &vbo_cube_vertices);
    glCreateBuffers(1, &vbo_cube_colors);
    glCreateBuffers(1, &ibo_cube_elements);

    glNamedBufferData(vbo_cube_vertices, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);
		glVertexArrayVertexBuffer
		(
			vaohandle,
			0, // binding index, vao
			vbo_cube_vertices,
			0, // offset
			sizeof(float)*3 // stride
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

    glNamedBufferData(vbo_cube_colors, sizeof(cube_colors), cube_colors, GL_STATIC_DRAW);
        glVertexArrayVertexBuffer
        (
            vaohandle,
            1,
            vbo_cube_colors,
            0,
            sizeof(float)*3 // stride
        );
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

    glEnableVertexArrayAttrib(vaohandle, 0);
    glEnableVertexArrayAttrib(vaohandle, 1);

        glNamedBufferData(ibo_cube_elements, sizeof(cube_elements), cube_elements, GL_STATIC_DRAW);
        glVertexArrayElementBuffer(vaohandle, ibo_cube_elements);
};

void ColorCube::draw()
{
    // 2. vao binding
	glBindVertexArray(vaohandle);
	// 3. cal draw func
	int size;
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE,&size); 
	glDrawElements(GL_TRIANGLES, size / sizeof(GLushort), GL_UNSIGNED_SHORT, 0);
}