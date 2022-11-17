#include "square.h"
#include <iostream>
using namespace std;
Square::Square() {
	this->color_num = 0;
}
Square::~Square() {

}
Sprite* Square::get_square() { return s_square; }
Sprite* Square::get_brocken_square() { return s_brocken_square; }
bool Square::setup() {
	if (!t_square.loadFromFile("C:\\Users\\Елизавета\\source\\repos\\tetris\\tetris\\image\\texture_squares.jpg")) {
		cout << "Ошибка загрузки текстуры квадрата!" << endl;
		return false;
	}
	if (!t_brocken_square.loadFromFile("C:\\Users\\Елизавета\\source\\repos\\tetris\\tetris\\image\\brocken_squares.jpg")) {
		cout << "Ошибка загрузки текстуры разрушенного квадрата!" << endl;
		return false;
	}
	srand(time(NULL));
	color_num = rand() % 6;
	s_brocken_square = new Sprite();
	s_square = new Sprite();
	s_square->setTexture(t_square);
	s_brocken_square->setTexture(t_brocken_square);
	s_square->setTextureRect(IntRect(color_num * 30, 0, 30, 30));
	s_brocken_square->setTextureRect(IntRect(color_num * 30, 0, 30, 30));
	return 0;
}