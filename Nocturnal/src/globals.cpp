// This file contains the implementations of these variables

#include "../header/globals.h" // Add relevant header files

// Game objects system
std::list<GameObjects*> gameObjects;
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

// Define window dimensions
const int windowWidth = 1280;
const int windowHeight = 720;
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

// Game variables and functions
float gameTime = 0.0f;
float spawnTime = static_cast<float>(GetRandomValue(1, 5));
float elapsedTime = 0.0f;
int score = 0;
bool isPlayerAlive = true;
bool gamePaused = false;

void restart()
{
	// Game reset system
	if (!isPlayerAlive && IsKeyPressed(KEY_R))
	{
		playerHealth = 100;
		bullets = 6;
		score = 0;
		isPlayerAlive = true;
		gameTime = 0.0f;
		elapsedTime = 0.0f;
	}
}

void pause() { if (IsKeyPressed(KEY_P)) { gamePaused = !gamePaused; } } // If P is pressed then toggle between pause and unpause
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

// Player variables
Vector2 playerPos = GetMousePosition();
float radius = 10.0f;
int bullets = 6;
int playerHealth = 100;
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

// Enemy variables
Vector2 enemyPos = { static_cast<float>(GetRandomValue(0, windowWidth - 100)), static_cast<float>(GetRandomValue(400, 500)) };
float enemyLifetime = 0.0f;
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/