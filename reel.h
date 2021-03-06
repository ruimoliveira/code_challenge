#ifndef reel_h
#define reel_h

#ifdef __linux__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <algorithm>
#include <random>
#include <stdio.h>
#include <string>

#include "constants.h"
#include "gameObject.h"
#include "slotScreen.h"

const int REEL_ROLL_H = 320;
const int REEL_ROLL_W = 120;
const int REEL_MARGIN = 5;
const int SYMBOL_W_H = 100;
const int SYMBOL_MARGIN = 10;
const int MAX_REEL_VELOCITY = 2755;
const int REEL_ACCELERATION = 13687;
const int REEL_DECELERATION = -5685;
const int REEL_SLOW_DECELERATION = -5685;
const int LOOK_AHEAD = 6;

enum reelPos { LEFT, MIDDLE, RIGHT };
enum reelStatus { REEL_STOPPED, REEL_ACCELERATING, REEL_MOVING, REEL_DECELERATING, REEL_FINISHED };

/**
 * @class Scene
 * @brief Implementation of slot machine reel
 */
class Reel{
public:
	Reel(int reelPos);
	~Reel() {};

	int ready();
	void update();
	void render();
	void clean();

private:
	GameObject * reelBackground;
	GameObject * gameSymbol;
	GameObject * topSymbol;
	GameObject * bottomSymbol;
	int * reelOrder;
	int position;
	int status;
	int reelHead;
	int spinsLeft;
	Uint32 lastFrameTick;
	float currentVelocity;
	int currentSymbolPosition;
	const std::string symbols[20] = { "ace", "apple", "bar", "cherry", "chest",
								 "chip7", "chipspades", "clover", "coin", "diamond",
								 "emerald", "grapes", "horseshoe", "jack", "king",
								 "nine", "queen", "seven", "shield", "watermelon" };

	void shuffle();
	void display();
	void initGameObjects(int xPos, int yPos);
	void roll(int distance);
	bool displayingTopSymbol();
	void swapSymbols();
	int getX();
};

#endif