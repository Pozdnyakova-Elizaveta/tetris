#pragma once
#include "Base_window.h"
#include "Shapes.h"
class Game :public Base_window //����� �������� ����
{
private:
	Texture grid;
	Sprite s_grid;//������� ����
	Sprite s_grid_next_shapes;//���� ��� ����������� ��������� ������
	Font font;//����� ��� ��������
	Texture button_main_menu;//������ ������ � ������� ����
	Sprite s_button_main_menu;
	int score;//���� ����
	//Shapes s7;
public:
	Game();
	void functioning();
};

