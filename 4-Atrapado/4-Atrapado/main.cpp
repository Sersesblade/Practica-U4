#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp> 
#include <iostream>

using namespace sf;
using namespace std;

Texture t_amarillo, t_verde;
Sprite s_amarillo,s_verde,s_enPantalla;


int main() {

	//Valores para escalar el sprite amarillo con el tamaño del sprite verde.
	float escalaX, escalaY;

	sf::Event evt;
	t_amarillo.loadFromFile("assets/cuad_yellow.png");
	s_amarillo.setTexture(t_amarillo);
	
	t_verde.loadFromFile("assets/rcircleg.png");
	s_verde.setTexture(t_verde);

	sf::RenderWindow ventana(sf::VideoMode(800, 600, 32), "Atrapado");

	ventana.setMouseCursorVisible(false);
	
	escalaX = (float)t_verde.getSize().x / (float)t_amarillo.getSize().x;
	escalaY = (float)t_verde.getSize().y / (float)t_amarillo.getSize().y;
	
	s_amarillo.setScale(escalaX, escalaY);

	s_enPantalla = s_amarillo;
	s_enPantalla.setPosition(300, 300);

	float limite_X = ventana.getSize().x - s_enPantalla.getGlobalBounds().width;
	float limite_Y = ventana.getSize().y - s_enPantalla.getGlobalBounds().height;

	//cout << limite_X << " " << limite_Y;

	//Bool False -> sprite amarillo. True -> sprite verde.
	bool change = false;
	
	//Velocidad de movimiento del Sprite en pantalla.
	float velocidad = 15;

	//Variable con posicion en X del sprite.
	float S_P_X;
	//Variable con posicion en Y del sprite.
	float S_P_Y;

	while (ventana.isOpen()) {

		//Mientras la ventana esta abierta, guardo la posicion actual del sprite en pantalla en dos variables.
		S_P_X = s_enPantalla.getPosition().x;
		S_P_Y = s_enPantalla.getPosition().y;

		while (ventana.pollEvent(evt)) {

			switch (evt.type) {

			case sf::Event::Closed:
				ventana.close(); break;
			
			case sf::Event::KeyPressed:

				if (evt.key.code == sf::Keyboard::Space) {
					//cout << "espacio presionado" << endl;
					
					//Cuando cambia de sprite el s_enPantalla vuelve a ser reescalado para que ambos texture puedan verse de igual tamaño al t_verde original.
					if (!change) { s_enPantalla.setTexture(t_verde); s_enPantalla.setScale(1.f,1.f); change = true; break; }
					else { s_enPantalla.setTexture(t_amarillo); s_enPantalla.setScale(escalaX, escalaY); change = false; break; }

				}


				if (evt.key.code == sf::Keyboard::Up) {

					//Compruevo la posicion del Sprite si esta en y= 0 o esta por llegar pero la velocidad lo supera fuerzo la posicion en 0,
					//evitando asi que siga subiendo.
					
					if (S_P_Y <= 0 || S_P_Y - velocidad <= 0) {
						s_enPantalla.setPosition(S_P_X, 0); break;
					}

					s_enPantalla.setPosition(S_P_X, S_P_Y - velocidad);  break;
				}
				if (evt.key.code == sf::Keyboard::Down) {

					if (S_P_Y >= limite_Y || S_P_Y + velocidad >= limite_Y) {
						s_enPantalla.setPosition(S_P_X, limite_Y); break; }

					s_enPantalla.setPosition(S_P_X, S_P_Y + velocidad); break;
				}
				if (evt.key.code == sf::Keyboard::Left) {

					if (S_P_X <= 0 || S_P_X - velocidad <= 0) {
						s_enPantalla.setPosition(0, S_P_Y); break;}

					s_enPantalla.setPosition(S_P_X - velocidad, S_P_Y); break;
				}
				if (evt.key.code == sf::Keyboard::Right) {

					if (S_P_X >= limite_X || S_P_X + velocidad >= limite_X) {
						s_enPantalla.setPosition(limite_X, S_P_Y); break;}

					
					s_enPantalla.setPosition(S_P_X + velocidad, S_P_Y); break;
				}

			}
		}


		ventana.clear(sf::Color::White);

		ventana.draw(s_enPantalla);

		ventana.display();
	}
	return 0;
}