#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

struct Key
{
	Key()
	{
		active = false;
		firstFrame = false;
	}

	bool active;
	bool firstFrame;
};

class InputManager
{
public:
	static void PollKey(int key, bool active);
	static void UpdateKeys();

	static bool Pressed(int key);
	static bool Held(int key);
	static bool Released(int key);
	
private:
	static Key keys[1024];
	static bool keyPoll[1024];
};

#endif