#include "core.h"

int main(int argc, char* args[]) {
	core Spacejunk;
	if(Spacejunk.initCore("Spacejunk", 800, 600, false, false)){
		SDL_Delay(2000);
	}
	return 0;
}