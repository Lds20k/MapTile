#include "textures.h"



textures::textures()
{
	texture = NULL;
}

textures::textures(const char* path, SDL_Renderer* render)
{
	SDL_Surface* convert;
	char* abPath = SDL_GetBasePath();
	strcat_s(abPath, (strlen(abPath) + strlen(path) + 1), path);
	convert = IMG_Load(abPath);
	texture = SDL_CreateTextureFromSurface(render ,convert);
	SDL_FreeSurface(convert);
}

textures::~textures()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}

void textures::draw(SDL_Renderer* render, SDL_Rect* srcrect, SDL_Rect* dstrect) {
	SDL_RenderCopy(render, texture, srcrect, dstrect);
}