#pragma once
#include <GL\glut.h>

class BackGround
{

private:
	GLuint texture; //Texture holder
	float x;
	float y;
	float z;
public:
	BackGround(float initX, float initY, float initZ);
	~BackGround();
	void Render();
};
