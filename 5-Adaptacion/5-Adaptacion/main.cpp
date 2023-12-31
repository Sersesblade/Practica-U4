#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp> 
#include <iostream>

using namespace sf;
using namespace std;


int main() {

	sf::Event evt;
	
	sf::RenderWindow ventana(sf::VideoMode(800, 600, 32), "Adaptación");

	Vector2u v_Pixeles;

	//Pixeles en x de la ventana.
	int v_X;
	//Pixeles en y de la ventana.
	int v_Y;


	//En caso de querer modificar el tamaño de la ventana desde la consola desmarcar.
	/*
	int X, Y;
	cout << "Ingresar tamaño en Pixeles en Y de la ventana." << endl;
	cin >> X;
	cout << "Ingresar tamaño en Pixeles en Y de la ventana." << endl;
	cin >> Y;

	v_Pixeles.x = X;
	v_Pixeles.y = Y;
	*/
	
	while (ventana.isOpen()) {

		//Para ajustar la ventana a los datos ingresados en consola desmarcar.
		//ventana.setSize(v_Pixeles);
		
		
		v_X = ventana.getSize().x;
		v_Y = ventana.getSize().y;

		if (1000 < v_X) { v_Pixeles.x = 1000; v_Pixeles.y = v_Y; ventana.setSize(v_Pixeles); cout << "Tamaño de la ventana reajustada en X." << endl; }
		if (1000 < v_Y) { v_Pixeles.x = v_X; v_Pixeles.y = 1000; ventana.setSize(v_Pixeles); cout << "Tamaño de la ventana reajustada en Y." << endl;}
		if (100 > v_X) { v_Pixeles.x = 100; v_Pixeles.y = v_Y; ventana.setSize(v_Pixeles); cout << "Tamaño de la ventana reajustada en X." << endl;}
		if (100 > v_Y) { v_Pixeles.x = v_X; v_Pixeles.y = 100; ventana.setSize(v_Pixeles); cout << "Tamaño de la ventana reajustada en Y." << endl;}


		while (ventana.pollEvent(evt)) {

			switch (evt.type) {

			case sf::Event::Closed:
				ventana.close(); break;

			case sf::Event::KeyPressed:
				if (evt.key.code == sf::Keyboard::Escape) {
					ventana.close(); break;
				}
				if (evt.key.code == sf::Keyboard::F1) {
					cout << "X: " << v_X << " Y:" << v_Y << endl;
				}
				
			}
		}
		ventana.clear();

		ventana.display();
	}
	return 0;
}

