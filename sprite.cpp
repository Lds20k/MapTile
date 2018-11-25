#include "sprite.h"

void sprite::reset() {
	next = NULL;
	previus = NULL;
	texture = NULL;
	srcrect.x = srcrect.y = srcrect.w = srcrect.h = NULL;
}

sprite::sprite()
{
	reset();
}

sprite::sprite(textures* texture, SDL_Rect* srcrect) {
	reset();
	this->texture = texture;
	this->srcrect = *srcrect;
}

sprite::~sprite()
{
	reset();
}

void sprite::setNext(sprite* next){
	this->next = next;
}

void sprite::setPrevius(sprite* previus){
	this->previus = previus;
}

sprite* sprite::getNext(){
	return next;
}

sprite* sprite::getPrevius(){
	return previus;
}

void sprite::drawn(SDL_Renderer* render, SDL_Rect* dstrect){
	texture->draw(render, &srcrect, dstrect);
}