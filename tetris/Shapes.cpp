#include "Shapes.h"
#include "square.h"
#include <iostream>
using namespace std; 

Shapes::Shapes() {

}
Shapes::~Shapes() {

}
void Shapes::Choice_shape(RenderWindow& w) {
	int i = rand() % 7;
	Square ss;
	Square ss1 = ss;
	Square ss2 = ss;
	Square ss3 = ss;
	if (i == 0) {//O
		ss.s_square.setPosition(31, 21);
		//w.draw(ss.s_square);
		ss1.s_square.setPosition(31, 58);
		//w.draw(ss1.s_square);
		ss2.s_square.setPosition(68, 21);
		//w.draw(ss2.s_square);
		ss3.s_square.setPosition(68, 58);
		//w.draw(ss3.s_square);
	}
	if (i == 1) {//L
		ss.s_square.setPosition(31, 21);
		//w.draw(ss.s_square);
		ss1.s_square.setPosition(31, 58);
		//w.draw(ss1.s_square);
		ss2.s_square.setPosition(31, 97);
		//w.draw(ss2.s_square);
		ss3.s_square.setPosition(68, 97);
		//w.draw(ss3.s_square);
	}
	if (i == 2) {//S
		ss.s_square.setPosition(31, 58);
		//w.draw(ss.s_square);
		ss1.s_square.setPosition(68, 58);
		//w.draw(ss1.s_square);
		ss2.s_square.setPosition(68, 21);
		//w.draw(ss2.s_square);
		ss3.s_square.setPosition(106, 21);
		//w.draw(ss3.s_square);
	}
	if (i == 3) {//Z
		ss.s_square.setPosition(31, 21);
		//w.draw(ss.s_square);
		ss1.s_square.setPosition(68, 21);
		//w.draw(ss1.s_square);
		ss2.s_square.setPosition(68, 58);
		//w.draw(ss2.s_square);
		ss3.s_square.setPosition(106, 58);
		//w.draw(ss3.s_square);
	}
	if (i == 4) {//J
		ss.s_square.setPosition(31, 97);
		//w.draw(ss.s_square);
		ss1.s_square.setPosition(68, 21);
		//w.draw(ss1.s_square);
		ss2.s_square.setPosition(68, 58);
		//w.draw(ss2.s_square);
		ss3.s_square.setPosition(68, 97);
		//w.draw(ss3.s_square);
	}
	if (i == 5) {//T
		ss.s_square.setPosition(31, 21);
		//w.draw(ss.s_square);
		ss1.s_square.setPosition(68, 21);
		//w.draw(ss1.s_square);
		ss2.s_square.setPosition(106, 21);
		//w.draw(ss2.s_square);
		ss3.s_square.setPosition(68, 58);
		//w.draw(ss3.s_square);
	}
	if (i == 6) {//I
		ss.s_square.setPosition(31, 21);
		//w.draw(ss.s_square);
		ss1.s_square.setPosition(31, 58);
		//w.draw(ss1.s_square);
		ss2.s_square.setPosition(31, 96);
		//w.draw(ss2.s_square);
		ss3.s_square.setPosition(31, 133);
		//w.draw(ss3.s_square);
	}
}