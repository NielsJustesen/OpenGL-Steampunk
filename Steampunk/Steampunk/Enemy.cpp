#include "Enemy.h"
#include <GL/glut.h>
#include <string>
#include "World.h"





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
	GameObject   *p = World::gameObjects[0];
	
	Attack(p);
}

void Enemy::Attack(Player *target)
{
	int dmg = 12;
	target->health = target->health - dmg;
	//char string = target->health;
	glColor3f(0.4, 0.1, 0.1);
	glRasterPos2f(0, 0);
	//int len, i;
	//len = (int)strlen(string);
	for (int i = 0; i < 2; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, target->health);
	}
}


Enemy::~Enemy()
{
}
