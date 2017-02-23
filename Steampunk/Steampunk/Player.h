#ifndef PLAYER_H
#define PLAYER_H
#include "Enemy.h"
#include "World.h"
#include "GameObject.h"
class Enemy;
class Player : public GameObject
{
public:
	primitiveshape ps1;
	float red1 = 0.4f;
	float green1 = 0.0f;
	float blue1 = 1.0f;
	World *world;
	Player(float health, World *world);
	void Render();
	void Update(char input);
	void HealthBar();
	void Spell1(Enemy *target);
	void Spell2(Enemy *target);
	~Player();
};
	
#endif

