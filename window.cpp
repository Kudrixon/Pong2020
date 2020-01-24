#include "window.h"
#include <iostream>
#include <SDL_ttf.h>

Window::Window(std::string title, int width, int height) : 
	_title(title), _width(width), _height(height) // konstruktor z listą inicjalizującą (piszą że tak sprawniej sprawniej)
{
	if (!init())
	{
		_opened = false;
	}
}

Window::~Window() //Zamykacz okna, rzeczy są zamykane w kolejności odwrotnej do inicjalizacji
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	SDL_Quit();
}

bool Window::init() // metoda inicjalizująca okno z ustalonymi wratościami
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		std::cout << "Nie działa Ci okno";
		return 0;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0); //Tworzy okno (plansze) gdzie odbywają się wszystkie eventy


	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED); // renderer jest odpowiedzialny za "rysowanie" rzeczy w oknie

	return true;
}

bool Window::opened() // metoda zwracająca stan okna
{
	return _opened; 

}

void Window::buttonevent() //metoda która pozwala na wyłączenie okna "X"-em 
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) 
	{
		if (event.type == SDL_QUIT)
		{
			_opened = false;
		}
		else if (event.type == SDL_KEYDOWN) //Sprawdza czy kalwisz byl klinkniety
		{
			if (event.key.keysym.sym == SDLK_ESCAPE) // Sprawdza jaki kalwisz byl klikniety
			{
				_opened = false;
			}
		}
	}

}

void Window::background(int red, int green, int blue) //metoda koloruje ekran wr RGB
{
	SDL_RenderPresent(_renderer); // RenderPresent musi być na końcu definicji ponieważ prezentujemy efekt po wszystkich modyfikacjach tutaj jest na początku żeby narysować Paletke wywołaną w mainie
	SDL_SetRenderDrawColor(_renderer, red, green, blue, 0);
	SDL_RenderClear(_renderer); // Potrzebne do wcześniejszego wyczszczenia ekranu
}
