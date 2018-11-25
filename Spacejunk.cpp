#include "core.h"

int main(int argc, char* args[]) {
	core Spacejunk;
	if(Spacejunk.initCore("Spacejunk", 800, 600, false, true)){
		bool running = true;
		SDL_Event events;

		textures tex("imagem.png",Spacejunk.getRender());
		tileDummy Red(32);
		Red.addNewFrame(0,0,32,32, &tex);

		tileDummy Blue(32);
		Blue.addNewFrame(32, 0, 32, 32, &tex);

		tileDummy Green(32);
		Green.addNewFrame(0, 32, 32, 32, &tex);

		tileDummy Yellow(32);
		Yellow.addNewFrame(32, 32, 32, 32, &tex);

		Spacejunk.loadMap("map.data");

		while(running){
			if(SDL_PollEvent(&events)){
				if(events.type == SDL_QUIT){
					running = false;
				}
				if(events.key.keysym.sym == SDLK_ESCAPE){
					running = false;
				}
			}
			Spacejunk.update();
		}
	}
	Spacejunk.finCore();
	return 0;
}