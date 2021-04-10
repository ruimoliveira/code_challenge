#ifndef engine_h
#define engine_h

#include "SDL.h"
#include "game.h"
#include "scene.h"
#include "constants.h"

#include <stdio.h>
#include <iostream>

/**
 * @class Engine
 * @brief Implementation of basic game engine functionality
 */
class Engine {
public:
	Engine() {};
	~Engine() {};
	void run();

private:
	SDL_Window * window;
	Game * game;
	Scene * scene;
	bool running;
	int gameState;

	void initWindow();
	void initGame();
	void initRenderer();
	void mainLoop();
	void clean();
	void handleEvents();
	void update();
	void render();
};

#endif