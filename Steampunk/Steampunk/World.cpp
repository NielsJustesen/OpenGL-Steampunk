#include "World.h"
#include <stdlib.h>
#include <GL/glut.h>
#include "Player.h"
#include "Enemy.h"



void World::Update()
{
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	for (GameObject * go : gameObjects)
	{
		go->Update();
	}


	
}

void World::Render()
{
	for (GameObject * go : gameObjects)
	{
		go->Render();
	}
	glutSwapBuffers();
	
	glFlush(); //Flush OpenGL Buffer

}

void World::AddEnemy()
{
	Enemy* e = new Enemy(100);
	it = toAdd.begin();
	it = gameObjects.insert(it, e);
}

World::World()
{
	Player* p = new Player(100);
	it = gameObjects.begin();
	it = gameObjects.insert(it, p);
	oldTimeSinceStart = 0;

	glEnable(GL_TEXTURE_2D); //Enable texture mapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces

}


World::~World()
{
}
