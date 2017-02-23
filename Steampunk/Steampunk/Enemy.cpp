#include "Enemy.h"
#include <GL/glut.h>
#include <string>





Enemy::Enemy(float health, World *world, bool type) : GameObject()
{
	this->health = health;
	this->world = world;
	this->type = type;
}

void Enemy::Render()
{
	if (type)
	{
		ps.Square(red, green, blue, 3.0f, -0.0f, -10.0f);
	}
	else
	{
		ps.Triangle(red, green, blue, 3.0f, -0.0f, -10.0f);
	}
	HealthBar();
}
void Enemy::HealthBar()
{
	glPushMatrix();
	glTranslatef(0.2f, -0.7f, -3.0f);
	glBegin(GL_QUADS); // Start drawing a quad primitive  
	if (this->health > 0)
	{
		glColor3f(1.0f, 0.0f, 0.0f); //Red color
		glVertex3f(-0.1f, -0.1f, 0.0f); // The bottom left corner  
		glColor3f(1.0f, 0.0f, 0.0f); //Red color
		glVertex3f(-0.1f, 0.1f, 0.0f); // The top left corner  
		glColor3f(1.0f, 0.0f, 0.0f); //Red color
		glVertex3f(this->health / 2, 0.1f, 0.0f); // The top right corner  
		glColor3f(1.0f, 0.0f, 0.0f); //Red color
		glVertex3f(this->health / 2, -0.1f, 0.0f); // The bottom right corner  
	}
	glEnd();
	glPopMatrix();
}
void Enemy::Update(char input)
{
	Player * player = nullptr;
	for (GameObject * go : *(world->GetGameObjects()))
	{
		if (typeid(*go) == typeid(Player))
		{
			player = dynamic_cast<Player*>(go);

		}
	}
	if (player && input)
	{
		switch (input)
		{
		case 'a':
			red = 1;
			green = 0;
			blue = 0.5f;
			Attack(player);
			break;
		case 's':
			red = 0.5f;
			green = 0.2f;
			blue = 0;
			Attack(player);
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

void Enemy::Attack(Player *target)
{
	target->health = target->health - 0.20;
}


Enemy::~Enemy()
{
	delete world;
	world = nullptr;
}