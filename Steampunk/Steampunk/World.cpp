#include "World.h"
#include <GL/glut.h>



void World::Progress()
{
	rotation += 0.001f;


}

void World::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffer
	glLoadIdentity(); //loads the identity matrix on the matrix stack - essentially resetting any other matrixes
	glTranslatef(-0.7f, 0.0f, -3.0f);// Push eveything 5 units back into the scene, otherwise we won't see the primitive  
	//glRotatef(rotation, 0.0f, 0.0f, 1.0f); //Rotation around z axis
	glBegin(GL_TRIANGLES); //start writing triangle primitives
	glColor3f(1.0f, 0.0f, 0.0f); //Red color
	glVertex3f(-0.5f, 0.0f, 0.0f); //Issue vertex
	glColor3f(0.0f, 1.0f, 0.0f); //Green color
	glVertex3f(0.0f, 0.5f, 0.0f); //Issue vertex
	glColor3f(0.0f, 0.0f, 1.0f); //Blue color
	glVertex3f(0.5f, 0.0f, 0.0f); //Issue vertex
	glEnd(); //End writing last primitive
	
	glTranslatef(1.4f, 0.0f, 0.0f);
	glBegin(GL_QUADS); // Start drawing a quad primitive  
	glVertex3f(-0.1f, -0.1f, 0.0f); // The bottom left corner  
	glVertex3f(-0.1f, 0.1f, 0.0f); // The top left corner  
	glVertex3f(0.1f, 0.1f, 0.0f); // The top right corner  
	glVertex3f(0.1f, -0.1f, 0.0f); // The bottom right corner  
	glEnd();
	glFlush(); //Flush OpenGL Buffer

}

World::World()
{
	rotation = 0;
}


World::~World()
{
}
