#define GLM_ENABLE_EXPERIMENTAL 
#define GLM_SWIZZLE

#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/gtx/string_cast.hpp>

#include <glm/mat2x2.hpp>

int main()
{
	// math review 40p

	/*glm::vec4 v1 = { 1, -0, 1, -1 };
	glm::vec4 v2 = { 1, -0, 1, -1 };
	glm::vec4 v3 = { 1, -0, 1, -1 };
	glm::vec4 v4 = { 1, -0, 1, -1 };

	glm::mat4 m;
	m[0] = v1;
	m[1] = v2;
	m[2] = v3;
	m[3] = v4;

	std::cout << glm::to_string(m) << std::endl;

	glm::mat2 m2 = { 1, 0, 1, -1 };

	std::cout << glm::to_string(m2) << std::endl;*/

	/*glm::mat2 m = { 1, 0, 1, 0 };
	m = 2.0f * m;*/ // 기본 mat은 float 기반

	/*glm::mat3 A =
	{
		{1, 1, -1},
		{0, 2, 0},
		{2, 3, 1}
	};

	glm::mat3 B =
	{
		{1, 0, 0},
		{0, -1, 1},
		{0, 1, 2}
	};

	std::cout << glm::to_string(A * B) << "\n" <<
		glm::to_string(B * A) << std::endl;*/
	
	/*glm::mat2 m2
	{
		{1, 0},
		{1, -1}
	};

	glm::mat2 im = glm::inverse(m2);
	std::cout << glm::to_string(im) << std::endl;

	glm::mat2 ii = m2 * im;
	std::cout << glm::to_string(ii) << std::endl;*/
	// 결과값이 다르게 나옴

	glm::vec3 a(1, 2, 3);
	glm::mat3 m
	{
		{1, 0, 0},
		{2, -1, 0},
		{3, 0, 1}
	};

	std::cout << glm::to_string(a*m) << std::endl;
	std::cout << glm::to_string(m*a) << std::endl;

	return 0;
}