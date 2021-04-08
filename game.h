#ifndef game_h
#define game_h

#include "SDL.h"
#include "scene.h"
#include "constants.h"

#include <stdio.h>
#include <iostream>

enum gameStates { FINISHED, STARTED, PAUSED };

/**
 * @class Game
 * @brief Implementation of basic game engine functionality
 */
class Game {
public:
	Game() {};
	~Game() {};
	void run();

private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	Scene * scene;
	bool running;
	int gameState;

	void initWindow();
	void initRenderer();
	void mainLoop();
	void clean();
	void handleEvents();
	void update();
	void render();
};

#endif