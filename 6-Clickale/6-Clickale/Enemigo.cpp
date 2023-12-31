#include "Enemigo.h"


enemigo::enemigo(float sizeX, float sizeY)
{
	//Cargo las texturas.
	t_enemigo.loadFromFile("assets/et.png");
	s_enemigo.setTexture(t_enemigo);

	escalaX = sizeX / t_enemigo.getSize().x;
	escalaY = sizeY / t_enemigo.getSize().x;
	
	s_enemigo.setScale(escalaX, escalaY);
	s_enemigo.setPosition(220, 0);
}

void enemigo::nuevaPosicion() {
	float x, y;
	x = rand() % 500 + 0;
	y = rand() % 400 + 0;
	s_enemigo.setPosition(x, y);
}

//Devuelve el sprite del enemigo.
Sprite enemigo::get_sprite()
{
	return s_enemigo;
}