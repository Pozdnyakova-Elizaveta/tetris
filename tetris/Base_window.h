#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Base_window
{
protected:
	int length;
	int width;
	Texture background;
	Sprite s_background;
public:
	Base_window();
	virtual void functioning() = 0;

};

