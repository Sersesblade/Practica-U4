#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Texture t_cross;
Sprite s_cross;

int main() {
	//Tamaño en pixeles de la imagen en x e y.
	int x, y;


	sf::Event evt;

	sf::RenderWindow ventana(sf::VideoMode(800, 600, 32), "Crosshair");

	t_cross.loadFromFile("assets/crosshair.png");
	s_cross.setTexture(t_cross);

	s_cross.setOrigin(s_cross.getLocalBounds().width / (float)2, s_cross.getLocalBounds().height / (float)2);
	s_cross.setPosition(ventana.getSize().x / 2, ventana.getSize().y / 2);

	ventana.setMouseCursorVisible(false);

	while (ventana.isOpen())
	{

		while (ventana.pollEvent(evt)) {

			switch (evt.type) {

			case sf::Event::Closed:
				ventana.close(); break;

			/*
			case sf::Event::MouseMoved:
				s_cross.setPosition(evt.mouseMove.x, evt.mouseMove.y);
			*/
			}
		}
		ventana.clear(sf::Color::White);

		ventana.draw(s_cross);

		ventana.display();
	}
	return 0;
}