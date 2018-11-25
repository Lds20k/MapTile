#pragma once
#include "sprite.h"

class frames
{
	private:
		sprite* aux;
		sprite* first;
		void reset();
		void goToTheLast();
	public:
		frames();
		~frames();
		void addNewFrame(int x, int y, int width, int height, textures* texture);
		void goToTheNextFrame();
		void drawn(SDL_Renderer* render, SDL_Rect* dstrect);
};

