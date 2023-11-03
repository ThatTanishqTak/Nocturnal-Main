// This file is the player header

#ifndef PLAYER_H
#define PLAYER_H

// Add relevant header files
#include "globals.h"
#include "raylib.h"

class Player : public GameObjects
{
public:
	Player(); // Constructor
	~Player(); // Destructor

	virtual void update(); // Update function
	virtual void render(); // Render function

private:
	void shootAndReload(); // The player shoot and reload function
	void killPlayer(); // The player kill function
};

#endif