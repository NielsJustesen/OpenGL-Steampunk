#include "Player.h"



Player::Player(int health)
{	
}

void Player::Spell1(Enemy * target)
{
	int dmg = 10;
	target->health=target->health-dmg;
}

void Player::Spell2(Enemy * target)
{
	int dmg = 20;
	target->health = target->health - dmg;
}


Player::~Player()
{
}
