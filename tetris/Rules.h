#pragma once
#include "Base_window.h"
class Rules :public Base_window
{
private:
	//Text rules;//������ ����
	Texture button_main_menu;//������ ������ � ������� ����
	Sprite s_button_main_menu;
	Font font;//����� ������
public:
	Rules();
	void functioning();
};


