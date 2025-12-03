#include <iostream>
#include <GL/gl3w.h>

class ColorCube
{
private:
	void setup();

	GLuint vaohandle;
	GLuint vbo_cube_vertices;
	GLuint vbo_cube_colors;
	GLuint ibo_cube_elements;

public:
    ColorCube();
	void draw();
};

