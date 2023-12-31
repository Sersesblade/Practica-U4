#include "crosshair.h"


crosshair::crosshair(float posx, float posy) {

	t_crosshair.loadFromFile("assets/crosshair.png");
	s_crosshair.setTexture(t_crosshair);
	s_crosshair.setPosition(posx, posy);
	s_crosshair.setScale(0.5f, 0.5f);

	s_crosshair.setOrigin(s_crosshair.getLocalBounds().width / (float)2, s_crosshair.getLocalBounds().height / (float)2);
	

}

void crosshair::move_sprite(float a, float b) {
	s_crosshair.setPosition(a, b);
}

Texture crosshair::get_texture() {
	return t_crosshair;
}

Sprite crosshair::get_sprite() {
	return s_crosshair;
}