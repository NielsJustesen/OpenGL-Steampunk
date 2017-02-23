#ifndef PLAYER_H
#define PLAYER_H
#include "Enemy.h"
#include "World.h"
#include "GameObject.h"
class Enemy;
class Player : public GameObject
{
public:
	World world;
	Player(float health, World world);
	void Render();
	void Update(char input);
	void HealthBar();
	void Spell1(Enemy *target);
	void Spell2(Enemy *target);
	~Player();
};
	
#endif

