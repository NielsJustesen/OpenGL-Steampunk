#pragma once
#include "Player.h"
class Enemy
{
	int health;
public:
	Enemy();
	void Attack(Player target);
	~Enemy();
};

