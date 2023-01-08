#pragma once
#include "Base_window.h"
class Menu:public Base_window  {
private:
	Texture menu_title, rules_button, play_button;
	Sprite s_rules, s_title, s_play;
	static bool animation;
public:
	Menu();
	void functioning();
	void set_animation(bool a);
	bool get_animation();
};