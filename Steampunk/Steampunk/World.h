#ifndef WORLD_H
#define WORLD_H
#include "GameObject.h"
#include "Background.h"
#include <vector>
class World
{
private:
	BackGround * bg;
	GameObject * go;
	int oldTimeSinceStart;
public:
	std::vector<GameObject*>::iterator *it;
	std::vector<GameObject*> *gameObjects;
	std::vector<GameObject*> toAdd;
	std::vector<GameObject*> toRemove;

	World();
	//std::vector<GameObject*> & GetGameObjects();
	void InputHandler(char input);
	bool FindEnemy();
	void Update();
	void Render();
	void AddEnemy();
	void ClearEnemies();
	~World();
};
#endif
