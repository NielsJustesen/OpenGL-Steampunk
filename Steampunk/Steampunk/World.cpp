#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "Player.h"
#include "Enemy.h"
#include <algorithm>


void World::Update()
{
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	if (FindEnemy() == false)
	{
		AddEnemy();
	}
	for (GameObject * go : gameObjects)
	{
		go->Update();
	}



}



void World::Render()
{
	bg->Render();
	for (GameObject * go : gameObjects)
	{
		go->Render();
	}
	glutSwapBuffers();

	glFlush(); //Flush OpenGL Buffer

}
//returns false if there is an enemy in the game
bool World::FindEnemy()
{
	for (GameObject* go : gameObjects)
	{
		if (typeid(*go) == typeid(Enemy))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void World::AddEnemy()
{
	Enemy* e = new Enemy(100);
	it = toAdd.begin();
	for (GameObject * go : gameObjects)
	{
		if (typeid(*go) != typeid(*e))
		{
			it = toAdd.insert(it, e);
		}
		else
		{
			delete e;
			e = nullptr;
		}
	}
	for (GameObject * go : toAdd)
	{
		gameObjects.push_back(go);
	}



	toAdd.clear();
}

void World::ClearEnemies()
{
	it = toRemove.begin();
	for (GameObject * go : gameObjects)
	{
		if (go->health <= 0)
		{
			toRemove.push_back(go);
		}
	}
	toRemove.clear();
}

World::World()
{
	bg = new BackGround(0, 0, 0);
	Player* p = new Player(100);
	it = gameObjects.begin();
	it = gameObjects.insert(it, p);
	oldTimeSinceStart = 0;
	AddEnemy();
	glEnable(GL_TEXTURE_2D); //Enable texture mapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces

}


World::~World()
{
	delete bg;
	bg = nullptr;
}
