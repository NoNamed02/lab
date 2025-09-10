#define GLM_ENABLE_EXPERIMENTAL 
#define GLM_SWIZZLE

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
// glm == similar C Langauge, not oriented languege
//1. Point p(1, 4, -5)�� vector v(5, 1, 4) ��ŭ �̵��϶� /
//2. vector v1(1, 0, 0) �� vector v2(0, 1, 0)�� ���϶� /
//3. Vector v1(0, 1, 0) �� ���̸� �� �� ��ŭ Ű��ÿ�. /
//4. ������(8, 2, 5) �� ����(1, -1, 4)�� �մ� ���͸� ���Ͻÿ�
//5. vector v(1, 3, 4)�� ����ȭ(normalize)�Ͻÿ�
//6. 3���� vector v(1, -1, 4)�� 4�������ͷ� ��ȯ�ϰ� w���� 0���� �����Ͻÿ�
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