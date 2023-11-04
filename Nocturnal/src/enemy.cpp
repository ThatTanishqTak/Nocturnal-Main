// This file is the implementation of the enemy header file

// Add relevant header files
#include "../header/globals.h"
#include "../header/enemy.h"

Enemy::Enemy() { gameObjects.push_back(this); } // Add this to the game objects list

Enemy::~Enemy()
{
}

void Enemy::update()
{
	if (!gamePaused)
	{
		spawnEnemy(); // Spawn more enemies

		for (auto& enemy : enemies) // Cycle through all the enemies in the vector
		{
			if (enemy.isAlive) // Check if the enemy is alive
			{
				enemyAttack(); // Call the enemy attack function

				if (bullets >= 0) // Check if enough bullets are available
				{
					if (CheckCollisionCircleRec(playerPos, radius, enemy.enemyRec)) // Check the collision between bullet and enemy
					{
						score += 100; // Increment score
						enemy.isAlive = false; // De-spawn enemy
					}
				}
			}

			if (!isPlayerAlive && IsKeyPressed(KEY_R)) { enemies.clear(); } // Enemy reset system
		}
	}
}

void Enemy::render()
{
	if(isPlayerAlive)
	{
		for (const auto& enemy : enemies) // Cycle through all the enemies
		{
			if (enemy.isAlive) // Check if the enemy is alive
			{
				// Render the enemy
				DrawRectangle(static_cast<int>(enemy.enemyRec.x), static_cast<int>(enemy.enemyRec.y),
					static_cast<int>(enemy.enemyRec.width), static_cast<int>(enemy.enemyRec.height), WHITE);

				// Render the enemy shooting
				if (enemyLifetime >= 3.0f) { DrawCircle(static_cast<int>(enemy.enemyRec.x), static_cast<int>(enemy.enemyRec.y), 30.0f, YELLOW); }
			}
		}
	}
}

void Enemy::spawnEnemy()
{
	if (isPlayerAlive) { elapsedTime += GetFrameTime(); } // Add 1 second per second

	if (elapsedTime >= spawnTime && isPlayerAlive)
	{
		elapsedTime = 0.0f; // Reset the time since last spawn

		enemyStruct newEnemy; // Instantiate a new enemy
		newEnemy.enemyRec = { static_cast<float>(GetRandomValue(10, windowWidth - 100)), static_cast<float>(GetRandomValue(400, 500)), 
									50.0f, 50.0f}; // Set random position for the new enemy
		
		newEnemy.isAlive = true; // Make sure that enemy is alive
		enemies.push_back(newEnemy); // Add the new enemy to the vector

		spawnTime = static_cast<float>(GetRandomValue(1, 5)); // Set a random spawn time
	}
}

void Enemy::enemyAttack()
{
	if (isPlayerAlive) { enemyLifetime += GetFrameTime(); } // Incrementing the enemy lifetime by 1 second per second

	if (enemyLifetime >= 3.0f && isPlayerAlive) // If enemy is alive for more than 3 seconds then shoot
	{
		playerHealth -= 5; // decrement player health
		enemyLifetime = 0.0f; // reset enemy timer
	}
}