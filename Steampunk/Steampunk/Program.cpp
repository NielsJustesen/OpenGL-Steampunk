#include <iostream>
#include <irrKlang.h>
#include "Player.h"
#include "Enemy.h"
using namespace std;
using namespace irrklang;



void main()
{
	Player *p = new Player(100);
	Enemy *E = new Enemy(100);
	cout <<"enemy has: "<< E->health << endl;
	p->Spell1(E);
	cout << "enemy has: " << E->health << endl;
	getchar();








	/*ISoundEngine * engine = createIrrKlangDevice();

	engine->play2D("bark.wav");

	getchar();
	engine->drop();*/

}