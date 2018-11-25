#include "tile.h"

tileDummy* tileDummy::first = NULL;
tileDummy* tileDummy::current = NULL;

//Tile Dummy

void tileDummy::setPosition(int* x, int* y){
	dstrect.x = *x;
	dstrect.y = *y;
}

tileDummy::tileDummy(){
}

tileDummy::tileDummy(int m2) {
	this->frame = new frames;
	dstrect.w = m2;
	dstrect.h = m2;
	dstrect.x = dstrect.y = NULL;
	if(!first){
		first = this;
		previus = NULL;
		next = NULL;
		current = first;
	}
	else{
		goToLast();
		previus = current;
		current->next = this;
		next = NULL;
	}
}

tileDummy::~tileDummy(){

}

tileDummy* tileDummy::getPosition(int pos){
	current = first;
	for(int i = 1; i < pos; i++){
		current = current->next;
	}
	return current;
}

frames* tileDummy::getFrameOfPosition(int pos){
	tileDummy::getPosition(pos);
	return current->frame;
}

SDL_Rect* tileDummy::getRectOfPosition(int pos){
	tileDummy::getPosition(pos);
	return &current->dstrect;
}

void tileDummy::goToLast(){
	while(current->next){
		current = current->next;
	}
}

void tileDummy::addNewFrame(int x, int y, int width, int height, textures* texture){
	frame->addNewFrame(x, y, width, height, texture);
}
//Tile

void tile::setPosition(int* x, int* y){
	dstrect.x = *x;
	dstrect.y = *y;
}

tile::tile()
{
	dstrect.x = NULL;
	dstrect.y = NULL;
	dstrect.w = 32;
	dstrect.h = 32;
}

tile::tile(int x, int y, int type)
{
	setPosition(&x, &y);
	this->type = type;
	mFrame = tileDummy::getFrameOfPosition(type);
	dstrect.h = dstrect.w = tileDummy::getRectOfPosition(type)->w;
}

tile::~tile()
{
}

void tile::draw(SDL_Renderer* render){
	mFrame->drawn(render, &dstrect);
}
