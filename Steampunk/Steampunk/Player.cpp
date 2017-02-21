#include "Player.h"

#include <GL/glut.h>



Player::Player(int health) : GameObject()
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

void Player::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffer
	glLoadIdentity(); //loads the identity matrix on the matrix stack - essentially resetting any other matrixes
	glTranslatef(-0.7f, 0.0f, -3.0f);// Push eveything 5 units back into the scene, otherwise we won't see the primitive
	glBegin(GL_TRIANGLES); //start writing triangle primitives
	glColor3f(1.0f, 0.0f, 0.0f); //Red color
	glVertex3f(-0.5f, 0.0f, 0.0f); //Issue vertex
	glColor3f(0.0f, 1.0f, 0.0f); //Green color
	glVertex3f(0.0f, 0.5f, 0.0f); //Issue vertex
	glColor3f(0.0f, 0.0f, 1.0f); //Blue color
	glVertex3f(0.5f, 0.0f, 0.0f); //Issue vertex
	glEnd(); //End writing last primitive
}

void Player::Update()
{

}


Player::~Player()
{
}
