#include "map.h"

void map::reset(){
	tiles = NULL;
	objects = NULL;
	posMap = NULL;
}

map::map()
{
	reset();
}

map::map(int* mapSizeM2, int* tileSizeM2)
{
	createMap(mapSizeM2, tileSizeM2);
}

map::~map()
{
}

bool map::createMap(int* mapSize, int* tileSizeM2){
	/*
	this->mapSizeM2 = (*mapSize*32);
	this->tileSizeM2 = *tileSizeM2;

	this->size = this->mapSizeM2 / this->tileSizeM2;
	int x = 0, y = 0;

	if(( this->mapSizeM2 % this->tileSizeM2 ) == 0){
		this->posMap = new int**[size];
		for (int y = 0; x < size; x++) {
			this->posMap[x] = new int*[size];
			for (int y = 0; y < size; y++) {
				this->posMap[x][y] = new int[2];
			}
		}
		for (int i = 0; i < size; i++) {
			tileMap[i].setPosition(&x, &y);
			objectMap[i].setPosition(&x, &y);
			x += this->tileSizeM2;
			if (x >= this->mapSizeM2/2) {
				x = 0;
				y += this->tileSizeM2;
			}
		}
		if(!tileMap && !objectMap){
			return false;
		}
		return true;
	}
	else {
		return false;
	}
	*/
	return false;
}

bool map::loadMap(const char* file) {
	char* abPath = SDL_GetBasePath();
	strcat_s(abPath, (strlen(abPath) + strlen(file) + 1), file);
	std::ifstream load(abPath, std::ifstream::in);
	if(!load.is_open()){
		std::cout << "Could not open file: " << abPath << std::endl;
		return false;
	}
	load >> mapSizeM2;
	load >> tileSizeM2;
	if( !(mapSizeM2 % (int)sqrt(mapSizeM2)) ){

		//For Tiles
		int type, x = 0, y = 0;
		this->tiles = new tile*[mapSizeM2];
		for (int i = 0; i < mapSizeM2; i++) {
			type = 0;
			load >> type;
			if(type > 0){
				this->tiles[i] = new tile( x*tileSizeM2, y*tileSizeM2, type);
			}
			x++;
			if (x >= sqrt(mapSizeM2)) {
				x = 0;
				y++;
			}
		}

		//For objects
		x = y = 0;
		this->objects = new object*[mapSizeM2];
		for (int i = 0; i < mapSizeM2; i++) {
			type = 0;
			load >> type;
			if (type > 0) {
				this->objects[i] = new object( x*tileSizeM2, y*tileSizeM2, type);
			}
			else if(type == 0){
				this->objects[i] = NULL;
			}
			/*else{
				this->objects[i] = new object(x*tileSizeM2, y*tileSizeM2, 0);
			}*/
			x++;
			if(x >= sqrt(mapSizeM2)){
				x = 0;
				y++;
			}
		}
		if(objects && tiles){
			return true;
		}
		std::cout << "Allocator error!" << std::endl;
		return false;
	}
	std::cout << "Could not open file: " << abPath << std::endl;
	std::cout << "Map size is currupted!" << std::endl;
	return false;
}

void map::drawMap(SDL_Renderer* render){
	static int i;
	for (i = 0; i < mapSizeM2; i++) {
		tiles[i][0].draw(render);
		if(objects[i][0].iExist()){
			objects[i][0].draw(render);
		}
		
	}
}

void map::deleteMap(){
	delete[] this->tiles;
	delete[] this->objects;
	delete[] this->posMap;
	reset();
}