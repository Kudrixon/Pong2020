#include "Rect.h"

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
				_yrect -= 5;
			}
			else if (event.key.keysym.sym == SDLK_DOWN)
			{
				_yrect += 5;
			}
		}
	}

}