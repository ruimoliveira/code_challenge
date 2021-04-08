#ifndef game_h
#define game_h

#include "SDL.h"

#include <stdio.h>
#include <iostream>

class Game {
public:
	Game() {};
	~Game() {};
	void run();

private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	bool running;

	void initWindow();
	void initRenderer();
	void mainLoop();
	void clean();
	void handleEvents();
	void update();
	void render();
};

#endif