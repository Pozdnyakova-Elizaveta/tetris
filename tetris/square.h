#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Square
{
public:
	int color_num; //номер цвета фигуры
	Texture t_square;
	Texture t_brocken_square;
	Sprite s_square;//изображение квадрата фигуры
	Sprite s_brocken_square;//изображение разрушенного квадрата фигуры
public:
	Square();
	Square(Square& s1);//конструктор копирования
	~Square();
	Sprite get_square();
	Sprite get_brocken_square();
};

