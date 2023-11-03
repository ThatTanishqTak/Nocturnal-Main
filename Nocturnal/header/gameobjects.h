// This file is the implementation of the game objects system

#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

class GameObjects
{
public:
	GameObjects() = default; // Default constructor function
	~GameObjects() = default; // Default destructor function

	virtual void update() = 0; // Virtual update function
	virtual void render() = 0; // Virtual render function

private:
};

#endif