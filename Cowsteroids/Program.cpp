#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Game.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

Game* cowsteroids;

void main()
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cowsteroids", nullptr, nullptr);

	glewExperimental = true;
	glewInit();
	glGetError();

	glfwSetKeyCallback(window, keyCallback);

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	cowsteroids = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);

	cowsteroids->Initialize();
	cowsteroids->SetState(GameState::ACTIVE);

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glfwPollEvents();

		cowsteroids->ProcessInput(deltaTime);
		cowsteroids->Update(deltaTime);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		cowsteroids->Render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	else if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			cowsteroids->SetKey(key, true);
		}
		else if (action == GLFW_RELEASE)
		{
			cowsteroids->SetKey(key, false);
		}
	}
}