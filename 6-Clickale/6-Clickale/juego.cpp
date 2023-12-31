#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "juego.h"


using namespace sf;
using namespace std;


GameCore::GameCore(int x, int y, std::string nombre)
{
	ventana = new RenderWindow(VideoMode(x, y, 32), nombre);

	evt = new Event;


	//Inicializo las clases.

	mira = new crosshair((float)ventana->getSize().x / 2, (float)ventana->getSize().y / 2);


	for (int i = 0; i < 3; i++) {
		enemy[i] = new enemigo(mira->get_texture().getSize().x, mira->get_texture().getSize().y);
		enemy[i]->nuevaPosicion();
	}


	t_fondo.loadFromFile("assets/fondo.jpg");
	s_fondo.setTexture(t_fondo);
	s_fondo.setPosition(0, 0);


	t_fondo.setSmooth(true);
	x = (float)ventana->getSize().x;
	y = (float)ventana->getSize().y;
	fondo_x = (float)t_fondo.getSize().x;
	fondo_y = (float)t_fondo.getSize().y;

	escala_x = x / fondo_x;
	escala_y = y / fondo_y;

	s_fondo.setScale(escala_x, escala_y);

	ventana->setMouseCursorVisible(false);


	Upgrade();
}

void GameCore::Upgrade() {


	while (ventana->isOpen()) {

		while (puntos < 5) {

			while (ventana->pollEvent(*evt)) {

				switch (evt->type) {

				case sf::Event::Closed:
					ventana->close(); break;

				case sf::Event::MouseMoved:
					mira->move_sprite((float)evt->mouseMove.x, (float)evt->mouseMove.y);
					break;

				case Event::MouseButtonPressed:
					FloatRect Punteria(mira->get_sprite().getPosition(), (Vector2f)mira->get_texture().getSize());
					for (int i = 0; i < 3; i++) {
						if (enemy[i]->get_sprite().getGlobalBounds().intersects(Punteria)) {
							enemy[i]->nuevaPosicion();
							system("cls");
							puntos++; if (puntos > 5) { puntos = 5; }cout << "Objetivo eliminado " << puntos << "/5" << endl;
						}
					}


					break;
				}
			}

			ventana->clear(sf::Color::White);

			ventana->draw(s_fondo);

			for (int i = 0; i < 3; i++) {
				ventana->draw(enemy[i]->get_sprite());
			}
			ventana->draw(mira->get_sprite());


			ventana->display();
		}
		if (puntos >= 5) {
			cout << "GANASTE!!!"<<endl; ventana->close();
		}
	}
}