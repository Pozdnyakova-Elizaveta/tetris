#pragma once
#include "Base_window.h"
class Game :public Base_window
{
private:
	Texture grid;
	Sprite s_grid;
	Sprite s_grid_next_shapes;
public:
	Game();
	void functioning();
};

