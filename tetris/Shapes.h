#pragma once
#include <SFML/Graphics.hpp>
#include "square.h"
using namespace sf;
class Shapes
{
protected:
	int x, y, dx, form;
	Texture s;
	Sprite s1;
	Square ss;
	Square ss1;
	Square ss2;
	Square ss3;
	const char shapes[7] = { 'o' , 'l' , 's' , 'z' , 'j' , 't' , 'i' };
public:
	Shapes();
	~Shapes();
	void Choice_shape();
	void draw_s(RenderWindow& w);
	void fall();
	bool fall_check();
	void left();
	void right();
	bool left_check();
	bool right_check();
};