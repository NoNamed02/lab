#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{
	glm::vec3 camPos(5, 5, 5); // cameraPos
	glm::vec3 Look(0, 0, 0); // cameraTarget
	glm::vec3 Up(0, 1, 0); // Upvector

	std::cout << glm::to_string(lookAt(camPos, Look, Up)) << std::endl;

	return 0;
}

glm::mat4 lookAt(glm::vec3 campos, glm::vec3 look, glm::vec3 up)
{
	glm::vec3 move = look - campos;

	glm::vec3 NewZAxies = glm::normalize(look - campos);
	glm::vec3 NewXAxies = glm::normalize(up * NewZAxies);
	glm::vec3 NewYAxies = glm::normalize(up * NewXAxies);

	glm::mat4 viewingMat =
	{
		{ NewXAxies.x, NewYAxies.x, NewZAxies.x, 0 },
		{ NewXAxies.y, NewYAxies.y, NewZAxies.y, 0 },
		{ NewXAxies.z, NewYAxies.z, NewZAxies.z, 0 },
		{ 0 ,0, 0, 1}
	};

	return viewingMat;
}