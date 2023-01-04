#include "square.h"
#include <iostream>
using namespace std;
Square::Square() {
	t_square.loadFromFile("image\\texture_squares.jpg");
	t_brocken_square.loadFromFile("image\\brocken_squares.jpg");
	srand(time(NULL));
	color_num = rand() % 6;
	s_square.setTexture(t_square);
	s_square.setScale(1.2f,1.2f);
	s_brocken_square.setTexture(t_brocken_square);
	s_square.setTextureRect(IntRect(color_num * 30, 0, 30, 30));
	s_brocken_square.setTextureRect(IntRect(color_num * 30, 0, 30, 30));
}
Square::~Square() {

}
Sprite Square::get_square() { return s_square; }
Sprite Square::get_brocken_square() { return s_brocken_square; }