#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtx/string_cast.hpp>

int main()
{

	/* point move control */
	//glm::vec3 v(5, 6, 1);
	//glm::mat3 t(1.0);

	//t = glm::translate(t, glm::vec2(2, 3));

	//v = t * v;

	//std::cout << glm::to_string(t) << std::endl;
	//std::cout << glm::to_string(v) << std::endl;

	/* scale control */
	//glm::vec3 v(5, 6, 1);
	//glm::mat3 t(1.0);

	//t = glm::scale(t, glm::vec2(3, 4));

	//v = t * v;

	//std::cout << glm::to_string(t) << std::endl;
	//std::cout << glm::to_string(v) << std::endl;

	/* rotation control */
	//glm::vec3 v(5, 6, 1);
	//glm::mat3 t(1.0);

	//v = glm::rotate(t, glm::radians(45.0f)) * v;

	//std::cout << glm::to_string(t) << std::endl;
	//std::cout << glm::to_string(v) << std::endl;

	/* mix */
	glm::vec3 v(5, 6, 1);
	glm::mat3 t(1.0);

	v = glm::rotate(t, glm::radians(45.0f)) *
		glm::scale(t, glm::vec2(2,3)) *
		glm::translate(t, glm::vec2(5,5))* v;

	std::cout << glm::to_string(t) << std::endl;
	std::cout << glm::to_string(v) << std::endl;

	return 0;
}