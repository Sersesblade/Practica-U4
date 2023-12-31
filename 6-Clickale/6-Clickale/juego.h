#pragma once
#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp> 
#include <iostream>
#include "Enemigo.h"
#include "crosshair.h"

using namespace sf;
using namespace std;

class GameCore
{
public:
	//Contructor de la clase Principal.
	GameCore(int x, int y, std::string nombre);

	//Proceso que se repite hasta que la ventana se cierra.
	void Upgrade();


private:

	//Tamaño de la pantalla.
	float x, y;

	//Ventana del juego.
	RenderWindow* ventana;

	//evento
	Event* evt;

	//Tamaño fondo.
	float fondo_x, fondo_y;
	float escala_x, escala_y;

	//Sprite y Texture del fondo.
	sf::Texture t_fondo;
	sf::Sprite s_fondo;

	//Clase crosshair.
	crosshair* mira;
	//Clase enemigo.
	enemigo* enemy[3];

	//condicional fin de juego
	int puntos = 0;

};