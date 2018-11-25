#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class textures
{
	private:
		SDL_Texture* texture;
	public:
		textures();
		textures(const char* path, SDL_Renderer* render);
		~textures();
		void draw(SDL_Renderer* render, SDL_Rect* srcrect, SDL_Rect* dstrect);
};

