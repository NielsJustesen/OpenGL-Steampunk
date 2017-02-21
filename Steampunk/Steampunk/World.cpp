#include "World.h"
#include <stdlib.h>
#include <GL/glut.h>
#include "Player.h"
#include "Enemy.h"



void World::Update()
{
//	rotation += 0.001f;
//Calculate delta time
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;



	Player *p = new Player(100);
	Enemy *E = new Enemy(100);
}

void World::Render()
{

	glutSwapBuffers();
	
	glFlush(); //Flush OpenGL Buffer

}

World::World()
{
	//rotation = 0;
	oldTimeSinceStart = 0;

	glEnable(GL_TEXTURE_2D); //Enable texture mapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces

}


World::~World()
{
}
