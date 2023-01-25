#include "square.h"
#include <iostream>
using namespace std;
Square::Square() {
	t_square.loadFromFile("files\\texture_squares.jpg");//получение изображений квадратов
	t_brocken_square.loadFromFile("files\\brocken_squares.jpg");
	srand(time(NULL));
	color_num = rand() % 6;//рандомный выбор цвета квадрата
	s_square.setTexture(t_square);//редактирование изображений квадратов
	s_square.setScale(1.2f,1.2f);
	s_brocken_square.setTexture(t_brocken_square);
	s_brocken_square.setScale(1.2f, 1.2f);
	s_square.setTextureRect(IntRect(color_num * 30, 0, 30, 30));//получение одного квадрата
	s_brocken_square.setTextureRect(IntRect(color_num * 30, 0, 30, 30));
}
Square::Square(Square& s1) {//конструктор копирования квадратов
	this->s_square = s1.s_square;
	this->s_brocken_square = s1.s_brocken_square;
}
Square::~Square() {

}
Sprite Square::get_square() { return s_square; }
Sprite Square::get_brocken_square() { return s_brocken_square; }
int Square::get_x() {
	return x;
}
int Square::get_y() {
	return y;
}
void Square::set_x(int a) {
	x = a;
}
void Square::set_y(int a) {
	y = a;
}