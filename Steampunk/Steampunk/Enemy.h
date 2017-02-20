#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
class Player;
class Enemy
{
public:
	int health=100;
	Enemy(int health);
	void Attack(Player *target);
	~Enemy();
};
#endif
