#include "Camera.h"

#include <glm\mat4x4.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "ResourceManager.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::Update(glm::vec2 center, glm::vec2 halfSize, glm::vec2 worldSize, const char* shader, const char* uniform)
{
	//Limites para a camera nao mostrar fora do mundo
	if (center.x < halfSize.x)
	{
		center.x = halfSize.x;
	}
	else if (center.x + halfSize.x > worldSize.x)
	{
		center.x = worldSize.x - halfSize.x;
	}

	if (center.y < halfSize.y)
	{
		center.y = halfSize.y;
	}
	else if (center.y + halfSize.y > worldSize.y)
	{
		center.y = worldSize.y - halfSize.y;
	}

	//Define a matriz que desloca os objetos relativo a "camera"
	glm::mat4 projection = glm::ortho(center.x - halfSize.x, center.x + halfSize.x, center.y + halfSize.y, center.y - halfSize.y, -1.0f, 1.0f);	
	ResourceManager::GetShader(shader).Use().SetUniform(uniform, projection);
}
