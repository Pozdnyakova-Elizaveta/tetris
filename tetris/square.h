#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Square
{
private:
	int color_num; //����� ����� ������
	int x, y;//���������� ������
	Texture t_square;
	Texture t_brocken_square;
	
	Sprite s_brocken_square;//����������� ������������ �������� ������
public:
	Square();
	Square(Square& s1);//����������� �����������
	~Square();
	Sprite s_square;//����������� �������� ������
	Sprite get_square();
	Sprite get_brocken_square();
	int get_x();
	int get_y();
	void set_x(int a);
	void set_y(int a);
};

