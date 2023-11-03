// This is the user interface header file

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

// Add relevant header files
#include "globals.h"
#include "raylib.h"
#include <sstream>
#include <iomanip>

class UserInterface : public GameObjects
{
public:
	UserInterface(); // Constructor
	~UserInterface(); // Destructor

	virtual void update(); // Update function
	virtual void render(); // Render function

private:
	Texture2D background;

	std::string formatTime(float gameTime); // Function to get the time in XX:XX format
};

#endif