#pragma once
#include "tile.h"
#include "object.h"
#include <fstream>

class map
{
	private:
		object** objects;
		tile** tiles;
		int mapSizeM2, tileSizeM2;
		int* posMap;
		void reset();
	public:
		map();
		map(int* mapSizeM2, int* tileSizeM2);
		~map();
		bool createMap(int* mapSizeM2, int* tileSizeM2);
		bool loadMap(const char* path);
		void drawMap(SDL_Renderer* render);
		void deleteMap();
};

