#include "Base_window.h"
#include <iostream>
Base_window::Base_window() {
	length = 900;
	width = 800;
	background.loadFromFile("files\\background.jpg");
	s_background.setTexture(background);
}
Base_window::~Base_window() { std::cout << "Окно закрыто"; }