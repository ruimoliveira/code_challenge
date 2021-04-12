#ifndef engine_h
#define engine_h

#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#endif

#include <stdio.h>

#include "game.h"
#include "scene.h"
#include "constants.h"


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
	void handleEvents();
	void update();
	void render();
	void clean();
};

#endif