#include "window.h"
#include <iostream>

Window::Window(std::string title, int width, int height) : 
	_title(title), _width(width), _height(height) // konstruktor z list¹ inicjalizuj¹c¹ (pisz¹ ¿e tak sprawniej sprawniej)
{
	if (!init())
	{
		_opened = false;
	}
}

Window::~Window() //Zamykacz okna, rzeczy s¹ zamykane w kolejnoœci odwrotnej do inicjalizacji
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Window::init() // metoda inicjalizuj¹ca okno z ustalonymi wratoœciami
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		std::cout << "Nie dzia³a Ci okno";
		return 0;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0); //Tworzy okno (plansze) gdzie odbywaj¹ siê wszystkie eventy


	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED); // renderer jest odpowiedzialny za "rysowanie" rzeczy w oknie

	return true;
}

bool Window::opened() // metoda zwracaj¹ca stan okna
{
	return _opened; 

}

void Window::buttonevent() //metoda która pozwala na wy³¹czenie okna "X"-em 
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
	SDL_RenderPresent(_renderer); // RenderPresent musi byæ na koñcu definicji poniewa¿ prezentujemy efekt po wszystkich modyfikacjach tutaj jest na pocz¹tku ¿eby narysowaæ Paletke wywo³an¹ w mainie
	SDL_SetRenderDrawColor(_renderer, red, green, blue, 0);
	SDL_RenderClear(_renderer); // Potrzebne do wczeœniejszego wyczszczenia ekranu
}