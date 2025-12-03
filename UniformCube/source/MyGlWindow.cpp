
#define GLM_ENABLE_EXPERIMENTAL 
#include "MyGlWindow.h"
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Loader.h"

static float DEFAULT_VIEW_POINT[3] = { 5, 5, 5 };
static float DEFAULT_VIEW_CENTER[3] = { 0, 0, 0 };
static float DEFAULT_UP_VECTOR[3] = { 0, 1, 0 };

// glm::mat4 lookAt(glm::vec3 campos, glm::vec3 look, glm::vec3 up)
// {
//     glm::vec3 zaxis = glm::normalize(campos - look);
//     glm::vec3 xaxis = glm::normalize(glm::cross(up, zaxis));
//     glm::vec3 yaxis = glm::cross(zaxis, xaxis);

//     glm::mat4 view = {
//         {xaxis.x, yaxis.x, zaxis.x, 0},
//         {xaxis.y, yaxis.y, zaxis.y, 0},
//         {xaxis.z, yaxis.z, zaxis.z, 0},
//         {-glm::dot(xaxis, campos), -glm::dot(yaxis, campos), -glm::dot(zaxis, campos), 1}};

//     return view;
// }

MyGlWindow::MyGlWindow(int w, int h)
{
	// m_width = w;
	// m_height = h;

	// setupBuffer();
	// initialize();
	m_width = w;
	m_height = h;
	m_cube = 0;
	glm::vec3 viewPoint(DEFAULT_VIEW_POINT[0], DEFAULT_VIEW_POINT[1], DEFAULT_VIEW_POINT[2]);
	glm::vec3 viewCenter(DEFAULT_VIEW_CENTER[0], DEFAULT_VIEW_CENTER[1], DEFAULT_VIEW_CENTER[2]);
	glm::vec3 upVector(DEFAULT_UP_VECTOR[0], DEFAULT_UP_VECTOR[1], DEFAULT_UP_VECTOR[2]);
	float aspect = (w / (float) h);
	m_viewer = new Viewer(viewPoint, viewCenter, upVector, 45.0f, aspect);
	initialize();
	setupBuffer();
}

void MyGlWindow::initialize()
{
	m_cube = std::make_unique<ColorCube>();
}
void MyGlWindow::setupBuffer()
{
	shaderProgram = std::make_unique<ShaderProgram>();
	shaderProgram->initFromFiles("shaders/simple.vert", "shaders/simple.frag");

	shaderProgram->addUniform("model");
	shaderProgram->addUniform("view");
	shaderProgram->addUniform("projection");
}

void MyGlWindow::draw(void)
{
	// set background color
	glClearColor(0.2f, 0.2f, 0.2f, 1);
	// set delete buffer, 레스터라제이션 할때 두 개의 버퍼 color, depth
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, m_width, m_height);
    glEnable(GL_DEPTH_TEST);

	// 1. shader use
	shaderProgram->use();
	// // 사이에 함수 넣기

	glm::vec3 eye = m_viewer->getViewPoint();
	glm::vec3 look = m_viewer->getViewCenter();
	glm::vec3 up = m_viewer->getUpVector();
	glm::mat4 view = lookAt(eye, look, up);
 	glm::mat4 model = glm::mat4(1.0f);

	glm::mat4 mview = view * model;
	glm::mat4 projection = glm::perspective(
		glm::radians(45.0f),
		1.0f * m_width / m_height,
		0.1f,
		500.0f
	); // ??? 이거 맞나

	glm::mat4 mvp = projection * view * model;

	
	glUniformMatrix4fv(shaderProgram->uniform("mvp"), 1, GL_FALSE, glm::value_ptr(mvp));
    // glUniformMatrix4fv(shaderProgram->uniform("model"), 1, GL_FALSE, glm::value_ptr(model));
	// glUniformMatrix4fv(shaderProgram->uniform("view"), 1, GL_FALSE, glm::value_ptr(view));
	// glUniformMatrix4fv(shaderProgram->uniform("projection"), 1, GL_FALSE, glm::value_ptr(projection));


    if (m_cube)
        m_cube->draw();
	shaderProgram->disable();
}
