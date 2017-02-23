#include "World.h"
#include <GL/glut.h>
#include <SOIL.h>

World * world;


void InitOpenGL()
{
	glShadeModel(GL_SMOOTH); //Enable smooth shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); //Set clear color
	glClearDepth(1.0f); // Set clearing depth for depth buffer
	glEnable(GL_DEPTH_TEST); //Enable depth testing
	glDepthFunc(GL_LEQUAL); //Set depth buffer testing to less then or equal

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); //Specifies how colors/textures are interpolized on surfaces
	glEnable(GL_TEXTURE_2D); //Enable texture mapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //Specify how textures should be interpolized over surfaces

}

void Reshape(int width, int height)
{
	if (height == 0) { height = 1; } //Make sure no divide by zero can happen 
	glViewport(0, 0, width, height);//Reset the current viewport

	glMatrixMode(GL_PROJECTION); //Specify projection matrix stack
	glLoadIdentity(); //Reset projection matrix stack - top matrix

	gluPerspective(45.0f, width / height, 0.0f, 100.0f); //Set perspective to match current display size

	glMatrixMode(GL_MODELVIEW); //Specify model view matrix
	glLoadIdentity(); //reset model view matrix - top matrix

}

//Keyboard input method handle keyboard input from glut. Could potentially parse it to the GW for further handling
void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'a' || key == 's' || key == 'd')
	{
		world->InputHandler(key);
	}
	else if (key == 27)
	{
		exit(0);

	}
}

//Function used to create the gameloop. Used because glut (which is C based) can't call a c++ method directly
void GameLoop()
{
	world->Update();
	world->Render();
	glutPostRedisplay();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);//Init GLUT
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //Initialize glut display mode with rgb and alpha colors and Depth
	glutInitWindowSize(1200, 900); //Set window size
	glutInitWindowPosition(0, 0); //Set window position

	glutCreateWindow("SteamPunk Adventure"); //Create GLUT OpenGL Window

	InitOpenGL();
	glutReshapeFunc(&Reshape); //Takes a function pointer to the reshape function
	glutDisplayFunc(&GameLoop); //Takes a function pointer to the main loop / display function
	glutKeyboardFunc(&Keyboard); //Takes a function pointer to the keyboard input handling function
	world = new World(); //Creates a global varaible with the gameworld
	glutMainLoop(); //Start the glut main loop, only return when finish running the gameloop

}