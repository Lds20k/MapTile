#pragma once
#include "frames.h"

class tileDummy
{
private:
	static tileDummy* first;
	static tileDummy* current;
	tileDummy* next;
	tileDummy* previus;
	frames* frame;
	SDL_Rect dstrect;
	void setPosition(int* x, int* y);
	void goToLast();
public:
	tileDummy();
	tileDummy(int m2);
	~tileDummy();
	static tileDummy* getPosition(int pos);
	static frames* getFrameOfPosition(int pos);
	static SDL_Rect* getRectOfPosition(int pos);
	void addNewFrame(int x, int y, int width, int height, textures* texture);
};

class tile
{
	private:
		frames* mFrame;
		SDL_Rect dstrect;
		int type;
		void setPosition(int* x, int* y);
	public:
		tile();
		tile(int x, int y, int type);
		~tile();
		void draw(SDL_Renderer* render);
};