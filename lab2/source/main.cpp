#define GLM_ENABLE_EXPERIMENTAL 
#define GLM_SWIZZLE

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/constants.hpp>


const double DEGREES_TO_RADIANS = glm::pi<float>() / 180.0;
const double RADIAN_TO_DEGREES = 180.0 / glm::pi<float>();
int main()
{
	/*
	glm::vec3 v(2, -1, 1);
	glm::vec3 u(1, 1, 2);

	float up = dot(v, u);
	float down = glm::length(u) * glm::length(v);

	float answer = up / down;

	float degree = glm::acos(answer) * RADIAN_TO_DEGREES;

	std::cout << degree << std::endl;
	*/

	//// v = a + b
	//glm::vec3 v(1, 2, -1);
	//glm::vec3 unit_vector_b(0, 1, 0);

	//glm::vec3 b = unit_vector_b * dot(v, unit_vector_b);
	//glm::vec3 a = v - b;

	//std::cout << glm::to_string(a) << " = a\n"
	//		  << glm::to_string(b) << " = b" << std::endl;


	glm::vec3 n(0, 1, 0);
	glm::vec3 p(1, 0, 1);
	glm::vec3 x(-3, 3, 2);

	glm::vec3 v = x - p;

	float a = dot(v, n);
	return 0;
}