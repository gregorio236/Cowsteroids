#include "Camera.h"

#include <glm\mat4x4.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "ResourceManager.h"

void Camera::Update(glm::vec2 center, glm::vec2 halfSize, const char* shader, const char* uniform)
{
	//Define a matriz que desloca os objetos relativo a "camera"
	glm::mat4 projection = glm::ortho(center.x - halfSize.x, center.x + halfSize.x, center.y + halfSize.y, center.y - halfSize.y, -1.0f, 1.0f);	
	ResourceManager::GetShader(shader).Use().SetUniform(uniform, projection);
}
