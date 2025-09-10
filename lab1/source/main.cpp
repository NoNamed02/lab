#define GLM_ENABLE_EXPERIMENTAL 
#define GLM_SWIZZLE

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
// glm == similar C Langauge, not oriented languege
//1. Point p(1, 4, -5)를 vector v(5, 1, 4) 만큼 이동하라 /
//2. vector v1(1, 0, 0) 와 vector v2(0, 1, 0)들 더하라 /
//3. Vector v1(0, 1, 0) 의 길이를 두 배 만큼 키우시오. /
//4. 시작점(8, 2, 5) 과 끝점(1, -1, 4)를 잇는 벡터를 구하시오
//5. vector v(1, 3, 4)를 정규화(normalize)하시오
//6. 3차원 vector v(1, -1, 4)를 4차원벡터로 변환하고 w값을 0으로 설정하시오
int main()
{
	// Q1
	{
		glm::vec3 p(1, 4, -5);
		glm::vec3 v(5, 1, 4);
		std::cout << glm::to_string(glm::vec3(p + v)) << std::endl;
	}
	// Q2
	{
		glm::vec3 v1(1, 0, 0);
		glm::vec3 v2(0, 1, 0);
		std::cout << glm::to_string(glm::vec3(v1 + v2)) << std::endl;
	}
	// Q3
	{
		glm::vec3 v1(0, 1, 0);
		glm::vec3 v1_Answer = v1 * 2.0f;
		std::cout << glm::to_string(v1_Answer) << std::endl;
	}
	// Q4
	{
		glm::vec3 start_p(8, 2, 5);
		glm::vec3 end_p(1, -1, 4);
		std::cout << glm::to_string(end_p - start_p) << std::endl;
	}
	// Q5
	{
		glm::vec3 v(1, 3, 4);
		glm::vec3 nomalizePoint = glm::normalize(v);
		std::cout << glm::to_string(nomalizePoint) << std::endl;
	}
	// Q6
	{
		glm::vec3 v(1, -1, 4);
		glm::vec4 v4Dimension(v, 0);
		std::cout << glm::to_string(v4Dimension) << std::endl;
	}
	return 0;
}