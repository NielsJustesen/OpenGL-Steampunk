#ifndef PLAYER_H
#define PLAYER_H
#include "Enemy.h"
#include "GameObject.h"
class Enemy;
class Player : public GameObject
{
	
public:
	int health=100;
	Player(int health);
	void Render();
	void Update();
	void Spell1(Enemy *target);
	void Spell2(Enemy *target);
	~Player();
};
	
#endif

