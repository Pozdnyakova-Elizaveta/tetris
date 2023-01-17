#pragma once
#include "Base_window.h"
class Menu:public Base_window  {
private:
	Texture menu_title, rules_button, play_button;//изображения для меню
	Sprite s_rules, s_title, s_play;
	static bool animation;//переменная для выполнения/отключения анимации в меню
public:
	Menu();
	void functioning();
};