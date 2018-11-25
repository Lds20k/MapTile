#pragma once
#include "map.h"

class core
{
	private:
		SDL_Window* window;
		SDL_Renderer* render;
		map* gameMap;
		void reset();
	public:
		core();
		~core();
		bool initCore(const char* windowName, int width, int height, bool fullscreen = false, bool vsync = false);
		void update();
		void finCore();
		bool createMap(int blockAmount, int squareTile);
		bool loadMap(const char* file);
		SDL_Renderer* getRender();
};

