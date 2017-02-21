#pragma once
#include "GameObject.h"
#include <vector>
class World
{
private:
	GameObject * go;
	int oldTimeSinceStart;
public:
	std::vector<GameObject*>::iterator it;
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> toAdd;
	std::vector<GameObject*> toRemove;

	World();
	bool FindEnemy();
	void Update();
	void Render();
	void AddEnemy();
	void ClearEnemies();
	~World();
};

