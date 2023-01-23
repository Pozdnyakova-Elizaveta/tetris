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
	x = 31;
	y = 21;
	dx = 37;
}
Shapes::~Shapes() {

}
void Shapes::Choice_shape() {
	if (form == 0) {//O
		ss.x = x;
		ss.y = y;
		ss1.x = x;
		ss1.y = y + dx;
		ss2.x = ss1.x + dx;
		ss2.y = y;
		ss3.x = ss2.x;
		ss3.y = ss1.y;
	}
	if (form == 1) {//L
		ss.x = x;
		ss.y = y;
		ss1.x = x;
		ss1.y = y + dx;
		ss2.x = x;
		ss2.y = ss1.y + dx;
		ss3.x = x + dx;
		ss3.y = ss2.y;
	}
	if (form == 2) {//S
		ss.x = x;
		ss.y = y + dx;
		ss1.x = ss.x + dx;
		ss1.y = ss.y;
		ss2.x = ss1.x;
		ss2.y = y;
		ss3.x = ss2.x + dx;
		ss3.y = y;
	}
	if (form == 3) {//Z
		ss.x = x;
		ss.y = y;
		ss1.x = x + dx;
		ss1.y = y;
		ss2.x = ss1.x;
		ss2.y = ss1.y + dx;
		ss3.x = ss2.x + dx;
		ss3.y = ss2.y;
	}
	if (form == 4) {//J
		ss.x = x;
		ss.y = y + dx + dx;
		ss1.x = x + dx;
		ss1.y = y;
		ss2.x = x + dx;
		ss2.y = y + dx;
		ss3.x = x + dx;
		ss3.y = y + dx + dx;
	}
	if (form == 5) {//T
		ss.x = x;
		ss.y = y;
		ss1.x = x + dx;
		ss1.y = y;
		ss2.x = ss1.x + dx;
		ss2.y = y;
		ss3.x = x + dx;
		ss3.y = y + dx;
	}
	if (form == 6) {//I
		ss.x = x;
		ss.y = y;
		ss1.x = x;
		ss1.y = y + dx;
		ss2.x = x;
		ss2.y = ss1.y + dx;
		ss3.x = x;
		ss3.y = ss2.y + dx;
	}
}
void Shapes::draw_s(RenderWindow& w) {
	ss.s_square.setPosition(ss.x, ss.y);
	w.draw(ss.s_square);
	ss1.s_square.setPosition(ss1.x, ss1.y);
	w.draw(ss1.s_square);
	ss2.s_square.setPosition(ss2.x, ss2.y);
	w.draw(ss2.s_square);
	ss3.s_square.setPosition(ss3.x, ss3.y);
	w.draw(ss3.s_square);
}
void Shapes::fall() {
	ss.y += dx;
	ss1.y += dx;
	ss2.y += dx;
	ss3.y += dx;
}
bool Shapes::fall_check() {
	if (ss.y >= 690 || ss1.y >= 690 || ss2.y >= 690 || ss3.y >= 690)
		return true;
	else return false;
}