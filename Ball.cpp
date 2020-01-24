#include "Ball.h"
#include "Rect.h"


Ball::Ball(Window& window, int wrect, int hrect, int xrect, int yrect, int r, int g, int b, int a) :
	Window(window), _wrect(wrect), _hrect(hrect), _xrect(xrect), _yrect(yrect), _r(r), _g(g), _b(b), _a(a)
{

}
void Ball::movement()
{
	// KIERUNEK Y
	if (_yrect == 580 && _yoff == 0)
	{
		_yoff = 1;
	}
	else if (_yrect == 0 && _yoff == 1)
	{
		_yoff = 0;
	}
	else if (_yoff == 0)
	{
		_yrect+= _vel;
	}
	else if (_yoff == 1)
	{
		_yrect-= _vel;
	}
	// KIERUNEK X
	if (_xrect == 730 && _xoff == 0)
	{
		_xoff = 1;
	}
	else if (_xrect == 50 && _xoff == 1)
	{
		_xoff = 0;
	}
	else if (_xoff == 0)
	{
		_xrect+= _vel;
	}
	else if (_xoff == 1)
	{
		_xrect-= _vel;
	}


}

void Ball::draw()
{
	SDL_Rect ball;

	ball.w = _wrect;
	ball .h = _hrect;
	ball.x = _xrect;
	ball.y = _yrect;
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
	SDL_RenderFillRect(_renderer, &ball);
}

void Ball::speedup()
{
	SDL_Event  event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_b)
			{
				_vel += 1;
			}
			else if (event.key.keysym.sym == SDLK_n)
			{
				_vel -= 1;
			}
		}

	}

}

int Ball::ycollider()
{
	return _yrect;
}

int Ball::xcollider()
{
	return _xrect;
}

void Ball::resposition()
{
	_yrect = 390;
	_xrect = 290;
}
