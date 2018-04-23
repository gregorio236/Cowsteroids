#include "Camera.h"

#include <glm\gtc\matrix_transform.hpp>

#include "ResourceManager.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::Update(glm::vec2 center, glm::vec2 size, const char* shader, const char* uniform)
{
	glm::mat4 projection = glm::ortho(center.x - (size.x / 2), center.x + (size.x / 2), center.y + (size.y / 2), center.y - (size.y / 2));
	ResourceManager::GetShader(shader).Use().SetUniform(uniform, projection);
}
