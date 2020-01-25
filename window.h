#pragma once

#include <string>
#include <SDL.h>


class Window {
public:
	Window(std::string title, int width, int height);
	~Window();

	void buttonevent();
	bool opened();
	void background(int red, int green, int blue);

private:
	bool init();

private:
	SDL_Window *_window = 0;
	std::string _title;
	int _width = 800;
	int _height = 600;

	bool _opened = true;
public:
	static SDL_Renderer* renderer;
};
