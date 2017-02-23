#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
#include "World.h"
#include "GameObject.h"
class Player;
class Enemy : public GameObject
{
public:

	Enemy(float health, World world);
	void HealthBar();
	void Render();
	void Update(char input);
	void Attack(Player *target);
	~Enemy();
};
#endif
