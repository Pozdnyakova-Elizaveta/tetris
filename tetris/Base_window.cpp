#include "Base_window.h"
Base_window::Base_window() {
	length = 1100;
	width = 600;
	background.loadFromFile("image\\background.jpg");
	s_background.setTexture(background);
}
