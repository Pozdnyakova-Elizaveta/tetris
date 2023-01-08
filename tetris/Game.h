#pragma once
#include "Base_window.h"
class Game :public Base_window
{
private:
	Texture grid;
	Sprite s_grid;
	Sprite s_grid_next_shapes;
	Font font;
	Texture button_main_menu;
	Sprite s_button_main_menu;
	int score;
public:
	Game();
	void functioning();
};

