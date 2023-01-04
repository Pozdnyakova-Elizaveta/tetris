#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Square
{
public:
	int color_num;
	Texture t_square;
	Texture t_brocken_square;
	Sprite s_square;
	Sprite s_brocken_square;
public:
	Square();
	Square(Square& s1);
	~Square();
	Sprite get_square();
	Sprite get_brocken_square();
};

