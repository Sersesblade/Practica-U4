#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class enemigo
{
public:
	//Constructor que recibe la posicion Vector2f para el sprite.
	enemigo(float sizeX, float sizeY);

	//Devuelve el Sprite
	Sprite get_sprite();

	//Genera una posicion aleatoria para el sprite.
	void nuevaPosicion();

private:
	//Textura del enemigo
	Texture t_enemigo;

	//Sprite del enemigo
	Sprite  s_enemigo;

	float escalaX, escalaY;

};