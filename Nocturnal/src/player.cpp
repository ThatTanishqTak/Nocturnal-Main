// This file is the implementation of the player header file

// Add relevant header files
#include "../header/globals.h"
#include "../header/player.h"

Player::Player() { gameObjects.push_back(this); } // Add this to the game objects list

Player::~Player()
{
}

void Player::update()
{
	shootAndReload(); // Call the player shoot and reload mechanic

	pause(); // The pause function is only called when the player presses the P key

	restart(); // The restart function is only called when the conditions are met (!isPlayerAlive && IsKeyPressed(R))

	killPlayer(); // Call this function if the player's health reaches 0
}

void Player::render()
{
	if (!gamePaused && bullets > 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{ DrawCircle(static_cast<int>(playerPos.x), static_cast<int>(playerPos.y), radius, RED); }
}

void Player::shootAndReload()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && bullets > 0 && !gamePaused && isPlayerAlive) // Simple shoot and check mechanic
	{
		playerPos = GetMousePosition(); // Set player's current position to the most recent mouse position when the left mouse button is pressed
		bullets--; // Decrement the bullet by 1
	}
		
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && !gamePaused) { bullets = 6; } // Reload mechanic
}

void Player::killPlayer() { if (playerHealth <= 0) { isPlayerAlive = false; } } // If health is 0 then set isPlayerAlive to false