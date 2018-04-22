#include "InputManager.h"

Key InputManager::keys[1024];
bool InputManager::keyPoll[1024];

void InputManager::PollKey(int key, bool active)
{
	keyPoll[key] = active;
}

void InputManager::UpdateKeys()
{
	for (int i = 0; i < 1024; i++)
	{
		if (keys[i].active == keyPoll[i])
		{
			keys[i].firstFrame = false;
		}
		else
		{
			keys[i].active = keyPoll[i];
			keys[i].firstFrame = true;
		}
	}
}

bool InputManager::Pressed(int key)
{
	return keys[key].active && keys[key].firstFrame;
}

bool InputManager::Held(int key)
{
	return keys[key].active && !keys[key].firstFrame;
}

bool InputManager::Released(int key)
{
	return !keys[key].active && keys[key].firstFrame;
}
