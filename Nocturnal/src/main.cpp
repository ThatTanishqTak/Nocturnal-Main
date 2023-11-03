// This is the main game file

// Add all the relevant header files
#include "../include/raylib.h"
#include "../header/globals.h"		
#include "../header/gameobjects.h"		/* I HATE HEADERS AND INCLUDES */
#include "../header/userinterface.h"
#include "../header/player.h"
#include "../header/enemy.h"

int main()
{
	InitWindow(windowWidth, windowHeight, "Nocturnal"); // Initialize the window
	SetTargetFPS(60); // Lock the FPS

	// Declare the objects and call the constructors
	UserInterface userInterface;
	Enemy enemy;
	Player player;

	// Main game loop
	while (!WindowShouldClose())
	{
		// Call all the update loop from the game objects list								
		for (GameObjects* gameObjects : gameObjects) { gameObjects->update(); }

		BeginDrawing();
		ClearBackground(BLACK);

		// Call all the render loop from the game objects list
		for (GameObjects* gameObjects : gameObjects) { gameObjects->render(); }

		EndDrawing();
	}

	CloseWindow(); // De-Initialize the window

	return 0; // Exit code
}