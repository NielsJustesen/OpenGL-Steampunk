#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <GL\glut.h>
#include <primitiveshape.h>
class GameObject
{
private:
	GLuint texture; //Texture holder
public:
	float health;
	/*float x;
	float y;
	float z;*/
	GameObject(/*float initX, float initY, float initZ*/);
	virtual ~GameObject();
	virtual void Update();
	virtual void Render();
};
#endif // !GAMEOBJECT_H