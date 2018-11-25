#pragma once
#include "textures.h"

class sprite
{
	private:
		sprite* next;
		sprite* previus;
		textures* texture;
		SDL_Rect srcrect;
		void reset();
	public:
		sprite();
		sprite(textures* texture, SDL_Rect* srcrect);
		~sprite();
		void setNext(sprite* next);
		void setPrevius(sprite* previus);
		sprite* getNext();
		sprite* getPrevius();
		void drawn(SDL_Renderer* render, SDL_Rect* dstrect);
};

