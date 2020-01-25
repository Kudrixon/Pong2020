#pragma once

#include "window.h"

class Ball
{
public:
	Ball(int wrect, int hrect, int xrect, int yrect, int r, int g, int b, int a);

	void draw();
	void movement();
	void keyspeedup();
	void speedup();
	int xcollider();
	int ycollider();
	void resposition();
	int _xrect, _yrect;
	int _vel = 1;

private:
	int _wrect, _hrect;
	int _r, _g, _b, _a;
	int _yoff = 0;
	int _xoff = 0;
};
