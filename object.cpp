#include "object.h"

void object::setPosition(int* x, int* y) {
	dstrect.x = *x;
	dstrect.y = *y;
}

object::object()
{
	dstrect.x = NULL;
	dstrect.y = NULL;
	dstrect.w = 32;
	dstrect.h = 32;
}

object::object(int x, int y, int type)
{
	dstrect.x = NULL;
	dstrect.y = NULL;
	setPosition(&x, &y);
}

object::~object()
{
}

bool object::iExist(){
	if(this != NULL){
		return true;
	}
	return false;
}

void object::draw(SDL_Renderer* render) {
}