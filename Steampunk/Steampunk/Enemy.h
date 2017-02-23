#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
#include "World.h"
#include "GameObject.h"
#include <primitiveshape.h>


class Player;
class Enemy : public GameObject
{
public:
	World  *world;
	primitiveshape ps;
	float red = 0.4f;
	float green = 1.0f;
	float blue = 0.0f;
	bool type;
	Enemy(float health, World *world, bool type);
	void HealthBar();
	void Render();
	void Update(char input);
	void Attack(Player *target);
	~Enemy();
};
#endif
