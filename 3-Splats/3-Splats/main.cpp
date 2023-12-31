#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp> 
#include <iostream>

using namespace sf;
using namespace std;


sf::Texture Tc_rojo, Tc_azul;
sf::Sprite Sc_rojo,Sc_azul;

int main() {

	sf::Event evt;
	Tc_rojo.loadFromFile("assets/rcircle.png");
	Sc_rojo.setTexture(Tc_rojo);

	Tc_azul.loadFromFile("assets/rcircleb.png");
	Sc_azul.setTexture(Tc_azul);

	Sc_azul.setOrigin(Sc_azul.getLocalBounds().width / (float)2, Sc_azul.getLocalBounds().height / (float)2);
	Sc_rojo.setOrigin(Sc_rojo.getLocalBounds().width / (float)2, Sc_rojo.getLocalBounds().height / (float)2);

	sf::RenderWindow ventana(sf::VideoMode(800, 600, 32), "Splats");

	vector<Sprite> rojo;
	vector<Sprite> azul;
	
	while (ventana.isOpen()) {

		while (ventana.pollEvent(evt)) {

			switch (evt.type) {

			case sf::Event::Closed:
				ventana.close(); break;

			case sf::Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left)) {
					Sc_rojo.setPosition(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)));
					//break;
					rojo.push_back(Sc_rojo);
				}
				else {
					if (Mouse::isButtonPressed(Mouse::Right)) {
						Sc_azul.setPosition(ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana)));
						//break;
						azul.push_back(Sc_azul);
					}
				}
				/*
				cout << "Cantidad de puntos rojos en pantalla: " << rojo.size()<<endl;
				cout << "Cantidad de puntos azules en pantalla: " << azul.size() << endl;
				*/
				break;
			}
		}
		ventana.clear(sf::Color::White);

		for (int i = 0; i < rojo.size(); i++){ ventana.draw(rojo[i]); }
		for (int i = 0; i < azul.size(); i++) { ventana.draw(azul[i]); }

		ventana.display();
	}
	return 0;
}