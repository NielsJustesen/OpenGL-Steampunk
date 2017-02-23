#include "Background.h"

Background::Background(float initX, float initY, float initZ)
{
	x = initX;
	y = initY;
	z = initZ;
	texture = SOIL_load_OGL_texture(".\\Background.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y); //Load texture through soil
	glBindTexture(GL_TEXTURE_2D, texture); //bind texture
}
void Background::Render()
{
	glEnable(GL_TEXTURE_2D);
	glPushMatrix(); //Makes sure only this objects uses the current matrix
	glTranslatef(x, y, z);
	glBindTexture(GL_TEXTURE_2D, texture); //Bind texture for usage
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-5.0f, -5.0f, 5.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, -5.0f, 5.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 5.0f, 5.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-5.0f, 5.0f, 5.0f);
	glEnd();
	glPopMatrix(); //Makes sure only this objects uses the current matrix any manipulation of the matrix is lost
	glDisable(GL_TEXTURE_2D);
}

Background::~Background()
{
}
