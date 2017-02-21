#pragma once
#include <GL\glut.h>

class GameObject
{
private:
	GLuint texture; //Texture holder

public:
	/*float x;
	float y;
	float z;*/
	GameObject(/*float initX, float initY, float initZ*/);
	~GameObject();
	virtual void Update();
	virtual void Render();
};