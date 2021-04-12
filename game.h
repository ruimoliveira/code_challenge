#ifndef game_h
#define game_h

#include "SDL.h"
#include "constants.h"

#include <stdio.h>
#include <time.h>
#include <random>
#include <cmath>

enum gameStates { READY, STARTED, PLAYING, PAUSED, FINISHED };
enum mouseStates { MOUSE_UP, MOUSE_DOWN, MOUSE_IDDLE };
const int MIN_REEL_ROTATIONS = 1;
const int N_REELS = 3;
const int REEL_SIZE = 20;
const int CREDITS_PRIZE = 400;

/**
 * @class Game
 * @brief Implementation of game wide functions and variables
 */
class Game {
public:
	Game(SDL_Window * window);
	~Game() {};

	static void start();
	static SDL_Renderer * getRenderer();
	static int getGameState();
	static void setGameState(int gs);
	static int getMouseState();
	static void setMouseState(int ms);
	static int getCredits();
	static void setCredits(int c);
	static int getGameResult(int reelPosition);
	void clean();
private:
	static int credits;
	static SDL_Renderer * renderer;
	static int gameState;
	static int mouseState;
	static int gameResult[];

	static void computeResult();
};

#endif