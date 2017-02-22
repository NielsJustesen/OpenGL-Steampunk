#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
#include "GameObject.h"
class Player;
class Enemy : public GameObject
{
public:

	Enemy(float health);
	void HealthBar();
	void Render();
	void Update();
	void Attack(Player *target);
	~Enemy();
};
#endif
