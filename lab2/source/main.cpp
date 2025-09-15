#define GLM_ENABLE_EXPERIMENTAL 
#define GLM_SWIZZLE

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

const double DEGREES_TO_RADIANS = glm::pi<float>() / 180.0;
const double RADIAN_TO_DEGREES = 180.0 / glm::pi<float>();
int main()
{
	glm::vec3 v(2, -1, 1);
	glm::vec3 u(1, 1, 2);

	float up = dot(v, u);
	float down = glm::length(u) * glm::length(v);

	float answer = up / down;

	float degree = glm::acos(answer) * RADIAN_TO_DEGREES;

	std::cout << degree << std::endl;

	return 0;
}