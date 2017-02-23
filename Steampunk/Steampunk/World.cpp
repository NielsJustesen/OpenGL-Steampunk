#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <algorithm>
#include "Player.h"
#include "Enemy.h"
Player *p;
Enemy *e;
bool playerAlive = true;
bool enemyAlive = true;
bool enemyType = true;
void World::Update()
{
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = timeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = timeSinceStart;
	RemoveObjects();


}

std::vector<GameObject*> * World::GetGameObjects()
{
	return gameObjects;
}


void World::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffer
	glLoadIdentity(); //loads the identity matrix on the matrix stack - essentially resetting any other matrixes
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	bg->Render();


	for (GameObject * go : *gameObjects)
	{
		go->Render();
	}
	glPopMatrix();
	glutSwapBuffers();
	glFlush(); //Flush OpenGL Buffer

}
//returns false if there is an enemy in the game
bool World::FindEnemy()
{
	for (GameObject* go : *gameObjects)
	{
		if (typeid(*go) == typeid(Enemy))
		{
			return false;
		}
	}
	return true;
}

void World::AddEnemy()
{
	Enemy* newEnemy;
	if (enemyType == true)
	{
		newEnemy = new Enemy(2, this, enemyType);
		enemyType = false;
	}
	else 
	{
		newEnemy = new Enemy(2, this, enemyType);
		enemyType = true;
	}
	it = toAdd->begin();
	for (GameObject * go : *gameObjects)
	{
		if (typeid(*go) != typeid(*newEnemy))
		{
			it = toAdd->insert(it, newEnemy);
			enemyAlive = true;
		}
		else
		{
			delete newEnemy;
			newEnemy = nullptr;
		}
	}
	for (GameObject * go : *toAdd)
	{
		gameObjects->push_back(go);
	}
	toAdd->clear();
}

void World::RemoveObjects()
{
	it = toRemove->begin();
	for (GameObject * go : *gameObjects)
	{
		if (go->health <= 0)
		{
			toRemove->push_back(go);
		}
	}
	for (GameObject * go : *toRemove)
	{
		GameObject * tmp = nullptr;
		if (typeid(*go) == typeid(Enemy) && go->health >= 0)
		{
			tmp = dynamic_cast<Enemy*>(go);
			gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), tmp), gameObjects->end());
			enemyAlive = false;
			AddEnemy();
		}
		if (typeid(*go) == typeid(Player) && go->health >= 0)
		{
			tmp = dynamic_cast<Player*>(go);
			gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), tmp), gameObjects->end());
			playerAlive = false;
		}
	}
	toRemove->clear();
}
void World::InputHandler(char input)
{
	if (enemyAlive)
	{
		e->Update(input);
	}
	if (playerAlive)
	{
		p->Update(input);
	}
}
World::World()
{
	bg = new Background(0, 0, -12);
	p = new Player(2.0f, this);
	e = new Enemy(2.0f, this, enemyType);
	gameObjects = new std::vector<GameObject*>();
	toRemove = new std::vector<GameObject*>();
	toAdd = new std::vector<GameObject*>();
	it = gameObjects->begin();
	it = gameObjects->insert(it, p);
	gameObjects->push_back(e);
	oldTimeSinceStart = 0;


}


World::~World()
{
}
