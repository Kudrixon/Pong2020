#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include "Window.h"

class Text
{
public:
	std::string _message_text;

	Text(SDL_Renderer* renderer, const std::string& font_path, int font_size,const std::string& message_text, const SDL_Color &color);
	
	void show(int x, int y, SDL_Renderer* renderer);

	SDL_Texture* loadFont(SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message_text, const SDL_Color &color);

private:
	SDL_Texture* _text_texture = 0;
	SDL_Rect _text_rect; 
};