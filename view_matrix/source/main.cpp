#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include <glm/glm.hpp>
//#include <glm/gtx/transform.hpp>
//#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtx/string_cast.hpp>

/*
scale 1.3 all
translate 0 5 0
rotate 40 56 0
*/

int main()
{
	//glm::vec4 local(4.0f, 5.0f, 3.0f, 1.0f);

	//glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.3f, 1.3f, 1.3f));
	//glm::mat4 trans = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 5.0f, 0.0f));


	////rotat 
	//glm::mat4 rx = glm::rotate(glm::mat4(1.0f), glm::radians(40.0f), glm::vec3(1.0f, 0.0f, 0.0f)); // X축 회전 40도
	//glm::mat4 ry = glm::rotate(rx, glm::radians(56.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Y축 회전 56도
	//glm::mat4 rot = glm::rotate(ry, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f)); // Z축 회전 0도



	////S -> R ->T 
	////glm::mat4 model = rz * ry * rx * trans * scale;
	//glm::mat4 model = trans * rot * scale;
	////glm::mat4 model = trans * rz * ry * rx * scale;
	//glm::vec4 world = model * local;

	glm::mat4 view = {
		{0.83f, -0.30f, 0.47f, 0},
		{0, 0.84f, 0.54f, 0},
		{-0.56f, -0.45f, 0.7f, 0},
		{0, 0, -44.47f, 1.0f}
	};

	glm::mat4 in_view = glm::inverse(view);

	glm::vec3 camPos = in_view[3];

	glm::vec3 z_azis = glm::normalize(-in_view[2]);
	glm::vec3 look = camPos + z_azis * 10.0f;
	glm::vec3 up(0, 1, 0); // Upvector
	glm::mat4 my_view = lookAt(camPos, look, up);


	std::cout << glm::to_string(view) << "\n";

	std::cout << glm::to_string(my_view) << "\n";


	return 0;
}

glm::mat4 lookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up)
{
	glm::vec3 f = glm::normalize(center - eye);
	glm::vec3 s = glm::normalize(glm::cross(f, up));
	glm::vec3 u = glm::cross(s, f);

	glm::mat4 Result(1.0f);
	Result[0][0] = s.x;
	Result[1][0] = s.y;
	Result[2][0] = s.z;
	Result[0][1] = u.x;
	Result[1][1] = u.y;
	Result[2][1] = u.z;
	Result[0][2] = -f.x;
	Result[1][2] = -f.y;
	Result[2][2] = -f.z;
	Result[3][0] = -glm::dot(s, eye);
	Result[3][1] = -glm::dot(u, eye);
	Result[3][2] = glm::dot(f, eye);
	return Result;
}

//glm::mat4 lookAt(glm::vec3 camPos, glm::vec3 look, glm::vec3 up)
//{
//	//glm::vec3 z_axies = glm::normalize(look - camPos);
//	//glm::vec3 x_axies = glm::normalize(z_axies * up);
//	//glm::vec3 y_axies = glm::normalize(x_axies * z_axies);
//
//	glm::vec3 z_axies = glm::normalize(camPos - look);
//	glm::vec3 x_axies = glm::normalize(glm::cross(up, z_axies));
//	glm::vec3 y_axies = glm::cross(z_axies, x_axies);
//
//	glm::mat4 trans = glm::translate(glm::mat4(1.0f), -camPos);
//
//	glm::mat4 viewingMat =
//	{
//		{ x_axies.x, y_axies.x, z_axies.x, 0 },
//		{ x_axies.y, y_axies.y, z_axies.y, 0 },
//		{ x_axies.z, y_axies.z, z_axies.z, 0 },
//		{ 0 ,0, 0, 1}
//	};
//	
//	return viewingMat * trans;
//}

//glm::mat4 lookAt(glm::vec3 campos, glm::vec3 look, glm::vec3 up)
//{
//	glm::vec3 move = look - campos;
//
//	glm::vec3 NewZAxies = glm::normalize(look - campos);
//	glm::vec3 NewXAxies = glm::normalize(up * NewZAxies);
//	glm::vec3 NewYAxies = glm::normalize(up * NewXAxies);
//
//	glm::mat4 trans = glm::translate(glm::mat4(1), -campos);
//
//	glm::mat4 viewingMat =
//	{
//		{ NewXAxies.x, NewYAxies.x, NewZAxies.x, 0 },
//		{ NewXAxies.y, NewYAxies.y, NewZAxies.y, 0 },
//		{ NewXAxies.z, NewYAxies.z, NewZAxies.z, 0 },
//		{ 0 ,0, 0, 1}
//	};
//	return viewingMat * trans;
//}


//#define GLM_ENABLE_EXPERIMENTAL
//
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtx/transform.hpp>
//#include <glm/gtx/matrix_transform_2d.hpp>
//#include <glm/gtx/string_cast.hpp>
//
//int main()
//{
//	glm::vec3 camPos(5, 5, 5); // cameraPos
//	glm::vec3 Look(0, 0, 0); // cameraTarget
//	glm::vec3 Up(0, 1, 0); // Upvector
//
//	std::cout << glm::to_string(lookAt(camPos, Look, Up)) << std::endl;
//
//	return 0;
//}
//
//glm::mat4 lookAt(glm::vec3 campos, glm::vec3 look, glm::vec3 up)
//{
//	glm::vec3 move = look - campos;
//
//	glm::vec3 NewZAxies = glm::normalize(look - campos);
//	glm::vec3 NewXAxies = glm::normalize(up * NewZAxies);
//	glm::vec3 NewYAxies = glm::normalize(up * NewXAxies);
//
//	glm::mat4 trans = glm::translate(glm::mat4(1), -campos);
//
//	glm::mat4 viewingMat =
//	{
//		{ NewXAxies.x, NewYAxies.x, NewZAxies.x, 0 },
//		{ NewXAxies.y, NewYAxies.y, NewZAxies.y, 0 },
//		{ NewXAxies.z, NewYAxies.z, NewZAxies.z, 0 },
//		{ 0 ,0, 0, 1}
//	};
//
//	return viewingMat * trans;
//}