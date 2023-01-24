#pragma once
#include "Base_window.h"
class Rules :public Base_window
{
private:
	//Text rules;//првила игры
	Texture button_main_menu;//кнопка выхода в главное меню
	Sprite s_button_main_menu;
	Font font;//шрифт текста
public:
	Rules();
	void functioning();
};


