#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Texture textura;
Sprite sprite[4];

int main() {
	
	sf::Event evt;

	sf::RenderWindow ventana(sf::VideoMode(800, 600, 32), "Drag");

	ventana.setFramerateLimit(60);

	textura.loadFromFile("assets/rcircle.png");

	for (int i = 0; i < 4; i++) {
		sprite[i].setTexture(textura);
		sprite[i].setOrigin(sprite[i].getLocalBounds().width / (float)2, sprite[i].getLocalBounds().height / (float)2);
	}

	sprite[1].setPosition(800, 0);
	sprite[2].setPosition(0, 600);
	sprite[3].setPosition(800, 600);

	Vector2f mousePosicion;
	
	bool tomar_circulo = false; int mover;
	while (ventana.isOpen())
	{

		while (ventana.pollEvent(evt)) {

			//Contiene la posicion donde esta el mouse.
			mousePosicion = ventana.mapPixelToCoords(sf::Mouse::getPosition(ventana));

			switch (evt.type) {

			case sf::Event::Closed:
				ventana.close(); break;

			//Como el proceso del boton presionado solo se ejecuta una ves el mismo se utiliza pra comprobar la posicion del mouse dentro de la ventana.
			case sf::Event::MouseButtonPressed:
				
				for (int i = 0; i < 4; i++) {
					//mover = i;
					//Cuando se presiona el click del mouse usando la posicion anteriormente definida verifico si esta sobre alguno de los circulos.
					if (sprite[i].getGlobalBounds().contains(mousePosicion)) {
						sprite[i].setPosition(mousePosicion);
						//Si se comprueba que esta tocando un circulo este pasa a ser el que se va a mover.
						tomar_circulo = true;
						mover = i;
						break;
					}
				}
				//En caso de no presionar ningun circulo se cierra el proceso.
				break;

			case sf::Event::MouseMoved:

				if (tomar_circulo) {
					//El evento MouseMove permiete que el circulo se mueva con el mouse mientras esta siendo presionado. 
					sprite[mover].setPosition((float)evt.mouseMove.x, (float)evt.mouseMove.y);
				}
				break;

			case sf::Event::MouseButtonReleased:
				//En caso que el boton del mouse sea soltado el proceso que se repetia que permitia mover el circulo se detendra.
				tomar_circulo = false;
				break;
			}
		}
		//Como los sprites del circulo estan centrados al origen siempre que se precione con el rato algunas de las esquinas o cualquier parte del circulo
		//este se centrara con el mouse.

		ventana.clear();

		for (int i = 0; i < 4; i++) { ventana.draw(sprite[i]); }

		ventana.display();
	}

	return 0;
}