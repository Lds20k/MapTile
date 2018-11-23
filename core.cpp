#include "core.h"


void core::reset() {
	SDL_Window* window = NULL;
	SDL_Renderer* render = NULL;
}

core::core()
{
	reset();
}

core::~core()
{
	reset();
}

bool core::initCore(const char* windowName, int width, int height, bool fullscreen, bool vsync){
	Uint32 flags = SDL_WINDOW_VULKAN;
	if (fullscreen) {
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	if(!SDL_Init(SDL_INIT_VIDEO) && IMG_Init(IMG_INIT_PNG)){
		window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if(window){
			flags = SDL_RENDERER_ACCELERATED;
			if (vsync) {
				flags |= SDL_RENDERER_PRESENTVSYNC;
			}
			render = SDL_CreateRenderer(window, -1, flags);
			if(render){
				return true;
			}
		}
	}
	std::cout << "ERROR (1): " << SDL_GetError() << std::endl;
	std::cout << "ERROR (2): " << IMG_GetError() << std::endl;
	return false;
}
void core::update(){

}
void core::finCore(){

}
