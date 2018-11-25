#pragma once
#include "frames.h"

class object
{
	private:
		SDL_Rect dstrect;
		void setPosition(int* x, int* y);
	public:
		object();
		object(int x, int y, int type);
		~object();
		bool iExist();
		void draw(SDL_Renderer* render);
};

class objectDummy
{
private:
	objectDummy* next;
	objectDummy* previus;
	frames* currentFrame;
	int width;
	int height;
public:
	objectDummy();
	~objectDummy();
};


