#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

/*
Width = 780
Height = 750
FovY = 45.0f
NearZ = 0.1f;
FarZ = 500.0f;
*/

glm::mat4 perspective(float fovy, float aspect, float near, float far);

int main()
{
	float width = 780, height = 750, fov_y = 45.0f, near_z = 0.1f, far_z = 500.0f;
	
	glm::mat4 projection_matrix = perspective(fov_y, width/height, near_z, far_z);

	std::cout << glm::to_string(projection_matrix) << "\n";

	return 0;
}

glm::mat4 perspective(float fovy, float aspect, float near, float far)
{
	glm::mat4 pro_matrix =
	{
		{ 1/(aspect * std::tan(glm::radians(fovy/2))), 0, 0, 0 },
		{ 0, 1 / std::tan(glm::radians(fovy/2)), 0, 0 },
		{ 0 , 0, -((far + near) / (far - near)), -1 },
		{ 0, 0, -2.0f*((far*near)/(far-near)), 0 }
	};
	return pro_matrix;
}