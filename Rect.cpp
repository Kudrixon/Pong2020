#include "Rect.h"
#include "Ball.h"
Rect::Rect(Window &window, int wrect, int hrect, int xrect, int yrect, int r, int g, int b, int a) :
	Window(window), _wrect(wrect), _hrect(hrect), _xrect(xrect), _yrect(yrect), _r(r), _g(g), _b(b), _a(a)
{

}

void Rect::draw()
{
	SDL_Rect rect;

	rect.w = _wrect;
	rect.h = _hrect;
	rect.x = _xrect;
	rect.y = _yrect;
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
	SDL_RenderFillRect(_renderer, &rect);
}

void Rect::keyevent()
{
	SDL_Event  event;
	if(SDL_PollEvent(&event))
	{
		if(event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_UP)
			{
				_yrect -= 10;
			}
			else if (event.key.keysym.sym == SDLK_DOWN)
			{
				_yrect += 10;
			}
		}

	}

}

void Rect::movement() 
{
	// KIERUNEK Y
	if(_yrect == 599 && _yoff == 0)
	{
		_yoff = 1;
	}
	else if (_yrect == 1 && _yoff == 1)
	{
		_yoff = 0;
	}
	else if(_yoff == 0)
	{
		_yrect++;
		SDL_Delay(10);
	}
	else if(_yoff == 1)
	{
		_yrect--;
		SDL_Delay(10);
	}
	// KIERUNEK X
	if (_xrect == 799 && _xoff == 0)
	{
		_xoff = 1;
	}
	else if (_xrect == 1 && _xoff == 1)
	{
		_xoff = 0;
	}
	else if (_xoff == 0)
	{
		_xrect++;
	}
	else if (_xoff == 1)
	{
		_xrect--;
	}


}

int Rect::yer()
{
	return _yrect;
}
