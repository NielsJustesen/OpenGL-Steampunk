#include <iostream>
#include <irrKlang.h>
using namespace std;


using namespace irrklang;

void main()
{
	ISoundEngine * engine = createIrrKlangDevice();

	engine->play2D("bark.wav");

	getchar();
	engine->drop();

}