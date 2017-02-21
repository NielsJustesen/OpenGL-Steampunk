#include "Enemy.h"
#include <GL/glut.h>



Enemy::Enemy(int health)
{
	
}

void Enemy::Render()
{
	glTranslatef(1.4f, 0.0f, 0.0f);
	glBegin(GL_QUADS); // Start drawing a quad primitive  
	glVertex3f(-0.1f, -0.1f, 0.0f); // The bottom left corner  
	glVertex3f(-0.1f, 0.1f, 0.0f); // The top left corner  
	glVertex3f(0.1f, 0.1f, 0.0f); // The top right corner  
	glVertex3f(0.1f, -0.1f, 0.0f); // The bottom right corner  
	glEnd();
}

void Enemy::Update()
{
}

void Enemy::Attack(Player *target)
{
	int dmg = 12;
	target->health = target->health - dmg;
	
}


Enemy::~Enemy()
{
}
