#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "Player.h"
#include "Enemy.h"
Player *p;
Enemy *e;
void World::Update()
{
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	for (GameObject * go : gameObjects)
	{
		go->Update();
	}
	ClearEnemies();


}

//std::vector<GameObject*> & World::GetGameObjects()
//{
//	return gameObjects;
//}


void World::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffer
	glLoadIdentity(); //loads the identity matrix on the matrix stack - essentially resetting any other matrixes

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
void World::InputHandler(char input)
{
	p->Update(input);
	e->Update(input);
}
World::World()
{
	bg = new BackGround(0, 0, 0);
	p = new Player(2);
	e = new Enemy(2);
	it = gameObjects.begin();
	it = gameObjects.insert(it, p);
	gameObjects.push_back(e);
	oldTimeSinceStart = 0;
	
	glEnable(GL_TEXTURE_2D); //Enable texture mapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces

}


World::~World()
{
	delete bg;
	bg = nullptr;
}
