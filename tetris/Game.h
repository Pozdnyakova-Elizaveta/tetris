#pragma once
#include "Base_window.h"
class Game :public Base_window
{
private:
	Texture grid;
	Sprite s_grid;
public:
	Game();
	void functioning();
};

