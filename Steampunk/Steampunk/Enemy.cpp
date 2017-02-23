#include "Enemy.h"
#include <GL/glut.h>
#include <string>
#include "World.h"
#include <primitiveshape.h>

primitiveshape ps;
float red = 0.4f;
float green = 1.0f;
float blue = 0.0f;
Enemy::Enemy(float health) : GameObject()
{
	this->health = health;
}

void Enemy::Render()
{
	//glPushMatrix();
	//
	//glTranslatef(3.5f, -0.0f, -3.0f);
	//glBegin(GL_QUADS); // Start drawing a quad primitive  
	//glColor3f(0.0f, 0.0f, 1.0f);
	//glVertex3f(-0.1f, -0.1f, 0.0f); // The bottom left corner  
	//glVertex3f(-0.1f, 1.1f, 0.0f); // The top left corner  
	//glVertex3f(1.1f, 1.1f, 0.0f); // The top right corner  
	//glVertex3f(1.1f, -0.1f, 0.0f); // The bottom right corner
	//glPopMatrix();
	//glEnd();
	ps.Square(red, green, blue, -0.7f, -0.5f, -3.0f);
	HealthBar();
}
void Enemy::HealthBar()
{
	glPushMatrix();
	glTranslatef(1.6f, -1.0f, -3.0f);
	glBegin(GL_QUADS); // Start drawing a quad primitive  
	glColor3f(1.0f, 0.0f, 0.0f); //Red color
	glVertex3f(-0.1f, -0.1f, 0.0f); // The bottom left corner  
	glVertex3f(-0.1f, 0.1f, 0.0f); // The top left corner  
	glVertex3f(this->health, 0.1f, 0.0f); // The top right corner  
	glVertex3f(this->health, -0.1f, 0.0f); // The bottom right corner  
	glPopMatrix();
	glEnd();
}
void Enemy::Update(char input)
{
	switch (input)
	{
	case 'a':
		this->health -= 0.25f;
		break;
	case 's':
		this->health -= 0.50f;
		break;
	case 'd':
		this->health -= 0.75f;
		break;
	case 'f':
		this->health -= 1;
		break;
	default:
		break;
	}
	if (this->health <= 0)
	{
		health = 0;
	}
	///*GameObject   *p = World::gameObjects[0];
	//Attack(p);*/
	//glColor3f(0.4, 0.1, 0.1);
	//glRasterPos2f(2, 0);
	//int len, i;
	//len = (int)strlen("health: ");
	//for (int i = 0; i < len; i++) {
	//	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, this->health);
	//}
}

void Enemy::Attack(Player *target)
{
	//int dmg = 12;
	//target->health = target->health - dmg;
	////char string = target->health;
	//glColor3f(0.4, 0.1, 0.1);
	//glRasterPos2f(0, 0);
	////int len, i;
	////len = (int)strlen(string);
	//for (int i = 0; i < 2; i++) {
	//	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, target->health);
	//}
}


Enemy::~Enemy()
{
}
