#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Shapes
{
protected:
	int x, y;
	Texture s;
	Sprite s1;
	const char shapes[7] = { 'o' , 'l' , 's' , 'z' , 'j' , 't' , 'i' };
public:
	Shapes();
	~Shapes();
	void Choice_shape(RenderWindow& w);
};