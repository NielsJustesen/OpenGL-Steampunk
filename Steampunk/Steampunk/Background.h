#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <GL\glut.h>
#include <SOIL.h>
class Background
{
private:
	GLuint texture; //Texture holder
	float x;
	float y;
	float z;
public:
	Background(float initX, float initY, float initZ);
	~Background();
	void Render();
};
#endif // !BACKGROUND_H

