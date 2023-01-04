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
	w.draw(ss.s_square);
	ss2.s_square.setPosition(35, 35);
	w.draw(ss2.s_square);
	if (i == 0) {//O

	}
	if (i == 1) {//L

	}
	if (i == 2) {//S

	}
	if (i == 3) {//Z

	}
	if (i == 4) {//J

	}
	if (i == 5) {//T

	}
	if (i == 6) {//I

	}
}