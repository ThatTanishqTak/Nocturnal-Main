// This is the implementation of the user interface header file

// Add the relevant header files
#include "../header/globals.h"
#include "../header/userinterface.h"

UserInterface::UserInterface()
{ 
	background = LoadTexture("../textures/background/DesertForest.png");
	gameObjects.push_back(this); 
} // Add this to the game objects list

UserInterface::~UserInterface()
{
}

void UserInterface::update() { if (!gamePaused) { gameTime += GetFrameTime(); } } // Add 1 second per second to the total game time

void UserInterface::render()
{
	DrawTexture(background, 0, 0, WHITE);

	// Only render these if the player is alive
	if(isPlayerAlive)
	{
		// Basic user interface that are needed at all time
		DrawText(("TIME: " + formatTime(gameTime)).c_str(), 10, 0, 24, RED); // Render total game time
		DrawText(("SCORE: " + std::to_string(score)).c_str(), windowWidth - 160, 0, 24, RED); // Render score
		DrawText(("HEALTH: " + std::to_string(playerHealth)).c_str(), windowWidth - 160, 25, 24, GREEN); // Render player health

		if (bullets > 0) { DrawText(("BULLETS: " + std::to_string(bullets)).c_str(), 10, 25, 24, RED); } // If bullets > 0 then rneder this
		else // Else render this
		{
			DrawText("RELOAD!", 10, windowHeight - 50, 24, RED);
			DrawText("BULLETS: 0", 10, 25, 24, RED);
		}
	}
	else
	{
		DrawText("GAME OVER!", windowWidth / 2 - 130, windowHeight / 2 - 50, 50, RED); // The game over text
		DrawText("PRESS R TO RESTART", windowWidth / 2 - 255, windowHeight / 2 + 10, 50, RED); // Game restart text
	}

	if (gamePaused) { DrawText("GAME PAUSED", windowWidth / 2 - 155, windowHeight / 2, 50, RED); } // Game pause text
}

std::string UserInterface::formatTime(float gameTime)
{
	std::ostringstream time; // Variable to store the formatted time

	int minutes = static_cast<int>(gameTime) / 60; // Variable to store minutes
	int seconds = static_cast<int>(gameTime) % 60; // Variable to store the remaining seconds

	time << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << seconds; // Formatting the time

	return time.str(); // Returning the formatted time
}