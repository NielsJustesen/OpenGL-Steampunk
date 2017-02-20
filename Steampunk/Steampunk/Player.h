#pragma once
#include "Enemy.h"
class Player
{
	int *health;
	
public:
	Player();
	void Spell1(Enemy *target);
	void Spell2(Enemy *target);
	~Player();
};

	

