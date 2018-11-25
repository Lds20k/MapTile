#include "frames.h"

void frames::reset(){
	aux = NULL;
	first = NULL;
}

void frames::goToTheLast(){
	while(aux->getNext())
	{
		aux = aux->getNext();
	}
}

frames::frames()
{
	reset();
}

frames::~frames()
{
	aux = first;
	while(aux->getNext()){
		goToTheNextFrame();
		delete aux->getPrevius();
	}
	delete aux;
	reset();
}

void frames::addNewFrame(int x, int y, int width, int height, textures* texture){
	SDL_Rect srcrect;
	srcrect.x = x;
	srcrect.y = y;
	srcrect.w = width;
	srcrect.h = height;
	if(!first){
		reset();
		this->first = new sprite(texture, &srcrect);
		aux = first;
	}
	else{
		goToTheLast();
		this->aux->setNext(new sprite(texture, &srcrect));
		aux->getNext()->setPrevius(aux);
		aux = first;
	}
}

void frames::goToTheNextFrame(){
	if(aux->getNext()){
		aux = aux->getNext();
	}
	else if(aux != first){
		aux = first;
	}
}

void frames::drawn(SDL_Renderer* render, SDL_Rect* dstrect) {
	aux->drawn(render, dstrect);
	goToTheNextFrame();
}