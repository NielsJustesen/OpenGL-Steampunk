#pragma once
#include "GameObject.h"
class World
{
private:
	float rotation;
	GameObject * go;
	int oldTimeSinceStart;
public:
	World();
	void Update();
	void Render();
	~World();
};

