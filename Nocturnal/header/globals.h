// This file contains the declaration of all the global variables

#ifndef GLOBALS_H
#define GLOBALS_H

// Add relevant header files
#include "gameobjects.h"
#include "raylib.h"
#include <list>
#include <vector>

// Game objects system
extern std::list<GameObjects*> gameObjects;
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

// Define window dimensions
extern const int windowWidth;
extern const int windowHeight;
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

// Game variables and functions
extern float gameTime;
extern float spawnTime;
extern float elapsedTime;
extern int score;
extern bool isPlayerAlive;
extern bool gamePaused;

void restart();
void pause();
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

// Player variables
extern Vector2 playerPos;
extern float radius;
extern int bullets;
extern int playerHealth;
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

// Enemy variables
extern Vector2 enemyPos;
extern float enemyLifetime;
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

#endif