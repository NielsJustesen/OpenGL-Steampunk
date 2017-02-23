#include "Player.h"
#include "World.h"
#include <GL/glut.h>
#include <typeinfo>


	

Player::Player(float health, World *world) : GameObject()
{	
	this->health = health;
	this->world = world;
}

void Player::Spell1(Enemy * target)
{
	float dmg = 0.25f;
	target->health=target->health-dmg;
}

void Player::Spell2(Enemy * target)
{
	float dmg = 0.50;
	target->health = target->health - dmg;
}

void Player::Render()
{
	ps1.Player(red1, green1, blue1, -2.2f, -0.0f, -10.0f);
	HealthBar();
}

void Player::HealthBar()
{
	glPushMatrix();
	glTranslatef(-1.1f, -0.7f, -3.0f);
	glBegin(GL_QUADS); // Start drawing a quad primitive  
	glColor3f(1.0f, 0.0f, 0.0f); //Red color
	glVertex3f(-0.1f, -0.1f, 0.0f); // The bottom left corner  
	glVertex3f(-0.1f, 0.1f, 0.0f); // The top left corner  
	glVertex3f(this->health/2, 0.1f, 0.0f); // The top right corner  
	glVertex3f(this->health/2, -0.1f, 0.0f); // The bottom right corner  
	glEnd();
	glPopMatrix();
}

void Player::Update(char input)
{
	
	Enemy * enemy = nullptr;
	for (GameObject * go : *(world->GetGameObjects()))
	{
		if (typeid(*go) == typeid(Enemy))
		{
			enemy = dynamic_cast<Enemy*>(go);

		}
	}
	if (enemy && input)
	{
		switch (input)
		{
		case 'a':
			red1 = 0.4f;
			green1 = 0.0f;
			blue1 = 1.0f;
			Spell1(enemy);
			break;
		case 's':
			red1 = 1.0f;
			green1 = 0.0f;
			blue1 = 0.4f;
			Spell2(enemy);
			break;
		case 'd':
			this->health += 0.5f;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (input)
		{
		case 'd':
			this->health += 0.5f;
			break;
		default:
			break;
		}
	}
	if (this->health <= 0)
	{
		this->health = 0;
	}
	if (this->health >= 2)
	{
		this->health = 2;
	}
}


Player::~Player()
{
	delete world;
	world = nullptr;
}
