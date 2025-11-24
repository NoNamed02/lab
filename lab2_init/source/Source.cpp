
//#define GLFW_INCLUDE_GLU

#include <iostream>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <memory>

#include "MyGlWindow.h"

std::unique_ptr<MyGlWindow> win;

int main(void)
{
	/* Initialize the library */
	if (!glfwInit())
	{
	// Initialization failed
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	int width = 800;
	int height = 800;
	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* window= glfwCreateWindow(width, height, "OpenGL FrameWork", NULL,
	NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// create opengl context / what is context? = big struect
	glfwMakeContextCurrent(window);
	// init helper = loader for using opengl's func 
	if (gl3wInit())
	{
		fprintf(stderr, "failed to initialize OpenGL\n");
		return -1;
	}
	if (!gl3wIsSupported(3, 2))
	{
		fprintf(stderr, "OpenGL 3.2 not supported\n");
		return -1;
	}
	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
	glGetString(GL_SHADING_LANGUAGE_VERSION));
	// 모니터 refesh rate sync
	glfwSwapInterval(1); //enable vsync

	// create object - myglwindow object
	// win = new MyGlWindow(width, height);
	win = std::make_unique<MyGlWindow>(width, height);
	// close 되기 전까지 프로그램 실행
	while (!glfwWindowShouldClose(window))
	{
		// call draw() func every freame
		win -> draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}


