#pragma once

#include "window.h"

class Rect :public Window
{
public:
	Rect(Window &window, int wrect, int hrect, int xrect, int yrect, int r, int g, int b, int a);

	void draw();
	void keyevent();

private:
	int _wrect, _hrect;
	int _xrect, _yrect;
	int _r, _g, _b, _a;
};