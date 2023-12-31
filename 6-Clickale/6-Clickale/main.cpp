#include "juego.h"

int main()
{
	srand(time(NULL));

	GameCore* juego;
	juego = new GameCore(800, 600, "Clickale");


	return 0;
}