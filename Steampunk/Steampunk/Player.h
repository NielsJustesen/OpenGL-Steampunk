#ifndef PLAYER_H
#define PLAYER_H
#include "Enemy.h"
class Enemy;
class Player
{
	
public:
	int health=100;
	Player(int health);
	void Spell1(Enemy *target);
	void Spell2(Enemy *target);
	~Player();
};
	
#endif

