#pragma once
#include <SFML/Graphics.hpp>
#include "square.h"
using namespace sf;
class Shapes
{
private:
	int x[8] = { 31,68,106,143,180,217,254,293}, y, dx, form, num;
	Square ss;
	Sprite s1;
	Square ss1;
	Square ss2;
	Square ss3;
	const char shapes[7] = { 'o' , 'l' , 's' , 'z' , 'j' , 't' , 'i' };
public:
	Shapes();
	~Shapes();
	void Choice_shape();
	void Choice_shape_next();
	void draw_s(RenderWindow& w);
	void draw_next(RenderWindow& w, Shapes* s3);
	void fall();
	bool fall_check();
	void left();
	void right();
	bool left_check();
	bool right_check();
	void operator=(Shapes s2);
};