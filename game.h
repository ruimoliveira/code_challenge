#ifndef game_h
#define game_h

#include "SDL.h"

#include <stdio.h>
#include <iostream>

enum gameStates { FINISHED, STARTED, PAUSED };
enum mouseStates { MOUSE_UP, MOUSE_DOWN, MOUSE_IDDLE };

/**
 * @class Game
 * @brief Implementation of game wide functions and variables
 */
class Game {
public:
	Game(SDL_Window * window);
	~Game() {};

	static SDL_Renderer * getRenderer();
	static int getGameState();
	static void setGameState(int gs);
	static int getMouseState();
	static void setMouseState(int ms);
	void clean();
private:
	static SDL_Renderer * renderer;
	static int gameState;
	static int mouseState;
};

#endif