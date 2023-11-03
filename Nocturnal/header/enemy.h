// This file is the enemy header file

#ifndef ENEMY_H
#define ENEMY_H

// Add relevant header files
#include "globals.h"
#include "raylib.h"
#include <vector>

class Enemy : public GameObjects
{
public:
	Enemy(); // Constructor
	~Enemy(); // Destructor

	virtual void update(); // Update function
	virtual void render(); // Render function

private:

	// Structure to store the enemy data
	struct enemyStruct
	{
		Rectangle enemyRec;
		bool isAlive;
	};
	std::vector<enemyStruct> enemies;

	void spawnEnemy(); // Function to spawn enemies
	void enemyAttack(); // Function to manage the enemy attack system
};

#endif