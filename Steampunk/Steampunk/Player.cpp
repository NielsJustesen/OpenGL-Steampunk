
#include "Player.h"
#include "World.h"
#include <GL/glut.h>
#include <typeinfo>
#include <primitiveshape.h>


	primitiveshape ps1;
	float red1 = 0.4f;
	float green1 = 0.0f;
	float blue1 = 1.0f;
Player::Player(float health) : GameObject()
Player::Player(float health, World world) : GameObject()
{	
	this->health = health;
	this->world = world;
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

	//glPushMatrix();
	//glTranslatef(-0.7f, -0.5f, -3.0f);// Push eveything 5 units back into the scene, otherwise we won't see the primitive
	//glBegin(GL_TRIANGLES); //start writing triangle primitives
	//glColor3f(1.0f, 0.0f, 0.0f); //Red color
	//glVertex3f(-0.5f, 0.0f, 0.0f); //Issue vertex
	//glColor3f(0.0f, 1.0f, 0.0f); //Green color
	//glVertex3f(0.0f, 0.5f, 0.0f); //Issue vertex
	//glColor3f(0.0f, 0.0f, 1.0f); //Blue color
	//glVertex3f(0.5f, 0.0f, 0.0f); //Issue vertex
	/*glPopMatrix();*/
	//glEnd(); //End writing last primitive
	ps1.Player(red1, green1, blue1, -0.7f, -0.5f, -10.0f);
	HealthBar();
}

void Player::HealthBar()
{
	glPushMatrix();
	glTranslatef(-1.6f, -1.0f, -3.0f);
	glBegin(GL_QUADS); // Start drawing a quad primitive  
	glColor3f(1.0f, 0.0f, 0.0f); //Red color
	glVertex3f(-0.1f, -0.1f, 0.0f); // The bottom left corner  
	glVertex3f(-0.1f, 0.1f, 0.0f); // The top left corner  
	glVertex3f(this->health, 0.1f, 0.0f); // The top right corner  
	glVertex3f(this->health, -0.1f, 0.0f); // The bottom right corner  
	glPopMatrix();
	glEnd();
}

void Player::Update(char input)
{
	
	Enemy * enemy = nullptr;
	/*std::vector<GameObject*>::iterator it;
	for (it = World::GetGameObjects.begin(); it != World::GetGameObjects.end(); it++)
	{
		
	}*/
	for (GameObject * go : *(world.GetGameObjects()))
	{
		if (typeid(*go) == typeid(Enemy))
		{
			enemy = dynamic_cast<Enemy*>(go);

		}
	}
	if (enemy && input == 'a')
	{
		Spell1(enemy);
	}
}


Player::~Player()
{
}
