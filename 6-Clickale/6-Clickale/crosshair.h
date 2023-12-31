#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class crosshair
{
public:
	//Constructor que recibe la posicion Vector2f para el sprite.
	crosshair(float posx, float posy);

	//Devuelve el Sprite.
	Sprite get_sprite();
	//Devuelve la Textura.
	Texture get_texture();



	void move_sprite(float a, float b);

private:
	//Textura del crosshair
	Texture t_crosshair;

	//Sprite del crosshair
	Sprite  s_crosshair;

};