#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Game.h"
#include "InputManager.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

Game* cowsteroids;

void main()
{
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;

	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cowsteroids", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	glewInit();
	glGetError();

	glfwSetKeyCallback(window, keyCallback);

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);

	cowsteroids = new Game({ SCREEN_WIDTH, SCREEN_HEIGHT });

	cowsteroids->Initialize();

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glfwPollEvents();
		InputManager::UpdateKeys();

		cowsteroids->HandleInput(deltaTime);
		cowsteroids->Update(deltaTime);
		cowsteroids->Collisions();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		cowsteroids->Render(deltaTime);

		glfwSwapBuffers(window);

		if (cowsteroids->GetIsOver())
		{
			glfwSetWindowShouldClose(window, true);
		}
	}

	glfwTerminate();

	cowsteroids->ShowScoreboard();

	delete cowsteroids;
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
			InputManager::PollKey(key, true);
		}
		else if (action == GLFW_RELEASE)
		{
			InputManager::PollKey(key, false);
		}
	}
}