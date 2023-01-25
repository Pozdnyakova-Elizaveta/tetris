#include "Shapes.h"
#include "square.h"
#include <iostream>
using namespace std; 

Shapes::Shapes() {
	Square ss;
	Square ss1 = ss;
	Square ss2 = ss;
	Square ss3 = ss;
	form = rand() % 7;
	num = rand() % 8;
	y = 21;
	dx = 37;
}
Shapes::~Shapes() {

}
void Shapes::Choice_shape() {
	if (form == 0) {//O
		ss.set_x(x[num]);
		ss.set_y(y);
		ss1.set_x(x[num]);
		ss1.set_y(y + dx);
		ss2.set_x(ss1.get_x() + dx);
		ss2.set_y(y);
		ss3.set_x(ss2.get_x());
		ss3.set_y(ss1.get_y());
	}
	if (form == 1) {//L
		ss.set_x(x[num]);
		ss.set_y(y);
		ss1.set_x(x[num]);
		ss1.set_y(y + dx);
		ss2.set_x(x[num]);
		ss2.set_y(ss1.get_y() + dx);
		ss3.set_x(x[num] + dx);
		ss3.set_y(ss2.get_y());
	}
	if (form == 2) {//S
		ss.set_x(x[num]);
		ss.set_y(y + dx);
		ss1.set_x(ss.get_x() + dx);
		ss1.set_y(ss.get_y());
		ss2.set_x(ss1.get_x());
		ss2.set_y(y);
		ss3.set_x(ss2.get_x() + dx);
		ss3.set_y(y);
	}
	if (form == 3) {//Z
		ss.set_x(x[num]);
		ss.set_y(y);
		ss1.set_x(x[num] + dx);
		ss1.set_y(y);
		ss2.set_x(ss1.get_x());
		ss2.set_y(ss1.get_y() + dx);
		ss3.set_x(ss2.get_x() + dx);
		ss3.set_y(ss2.get_y());
	}
	if (form == 4) {//J
		ss.set_x(x[num]);
		ss.set_y(y + dx + dx);
		ss1.set_x(x[num] + dx);
		ss1.set_y(y);
		ss2.set_x(x[num] + dx);
		ss2.set_y(y + dx);
		ss3.set_x(x[num] + dx);
		ss3.set_y(y + dx + dx);
	}
	if (form == 5) {//T
		ss.set_x(x[num]);
		ss.set_y(y);
		ss1.set_x(x[num] + dx);
		ss1.set_y(y);
		ss2.set_x(ss1.get_x() + dx);
		ss2.set_y(y);
		ss3.set_x(x[num] + dx);
		ss3.set_y(y + dx);
	}
	if (form == 6) {//I
		ss.set_x(x[num]);
		ss.set_y(y);
		ss1.set_x(x[num]);
		ss1.set_y(y + dx);
		ss2.set_x(x[num]);
		ss2.set_y(ss1.get_y() + dx);
		ss3.set_x(x[num]);
		ss3.set_y(ss2.get_y() + dx);
	}
}
void Shapes::draw_s(RenderWindow& w) {
	ss.s_square.setPosition(ss.get_x(), ss.get_y());
	w.draw(ss.s_square);
	ss1.s_square.setPosition(ss1.get_x(), ss1.get_y());
	w.draw(ss1.s_square);
	ss2.s_square.setPosition(ss2.get_x(), ss2.get_y());
	w.draw(ss2.s_square);
	ss3.s_square.setPosition(ss3.get_x(), ss3.get_y());
	w.draw(ss3.s_square);
}
void Shapes::fall() {
	ss.set_y(ss.get_y() + dx);
	ss1.set_y(ss1.get_y() + dx);
	ss2.set_y(ss2.get_y() + dx);
	ss3.set_y(ss3.get_y() + dx);
}
bool Shapes::fall_check() {
	if (ss.get_y() >= 690 || ss1.get_y() >= 690 || ss2.get_y() >= 690 || ss3.get_y() >= 690)
		return true;
	else return false;
}
void Shapes::left() {
	ss.set_x(ss.get_x() - dx);
	ss1.set_x(ss1.get_x() - dx);
	ss2.set_x(ss2.get_x() - dx);
	ss3.set_x(ss3.get_x() - dx);
}
void Shapes::right() {
	ss.set_x(ss.get_x() + dx);
	ss1.set_x(ss1.get_x() + dx);
	ss2.set_x(ss2.get_x() + dx);
	ss3.set_x(ss3.get_x() + dx);
}
bool Shapes::left_check() {
	if (ss.get_x() == 31 || ss1.get_x() == 31 || ss2.get_x() == 31 || ss3.get_x() == 31)
		return true;
	else return false;
}
bool Shapes::right_check() {
	if (ss.get_x() > 360 || ss1.get_x() > 360 || ss2.get_x() > 360 || ss3.get_x() > 360)
		return true;
	else return false;
}