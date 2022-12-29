#include "Base_window.h"
Base_window::Base_window() {
	length = 1100;
	width = 650;
	background.loadFromFile("image\\background.jpg");
	s_background.setTexture(background);
}
Base_window::~Base_window() {}