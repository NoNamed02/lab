//#define  FREEGLUT_LIB_PRAGMAS  0

#include <iostream>
#include <GL/gl3w.h>
#include <string>
// #include "Program.h"
#include "colorCube.h"
#include "Viewer.h"
#include "Loader.h"


class MyGlWindow {
public:
	MyGlWindow(int w, int h);

	void setSize(int w, int h) { m_width = w; m_height = h; }
	void setAspect(float r) { m_viewer->setAspectRatio(r); }

	std::unique_ptr<ColorCube> m_cube;
	Viewer *m_viewer;

	int m_width;
	int m_height;

	void draw();
	void initialize();
private:
	GLuint vaohandle;
	
	std::unique_ptr<ShaderProgram> shaderProgram;
	
	void setupBuffer();
};
