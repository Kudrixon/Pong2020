#include "Text2.h"
#include <iostream>

Text::Text(SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message_text, const SDL_Color &color)
	: _message_text(message_text)
{
	_text_texture = loadFont(renderer, font_path, font_size, message_text, color);
	SDL_QueryTexture(_text_texture, 0, 0, &_text_rect.w, &_text_rect.h);
}

void Text::show(int x, int y, SDL_Renderer* renderer)
{
	_text_rect.x = x;
	_text_rect.y = y;
	SDL_RenderCopy(renderer, _text_texture, 0, &_text_rect);
}

SDL_Texture *Text::loadFont(SDL_Renderer* renderer, const std::string &font_path, int font_size, const std::string& message_text, const SDL_Color &color)
{
	TTF_Font* font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font)
	{
		std::cout << TTF_GetError();
	}
	
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!text_surface)
	{
		std::cout << "Text Surface ERROR";
	}

	auto text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture) 
	{
		std::cout << "Texture ERROR";
	}
	SDL_FreeSurface(text_surface);
	TTF_CloseFont(font);

	return text_texture;
}