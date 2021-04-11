#ifndef reel_h
#define reel_h

#include "SDL.h"
#include "constants.h"
#include "gameObject.h"
#include "slotScreen.h"

#include <algorithm>
#include <random>
#include <stdio.h>
#include <string>

const int REEL_ROLL_H = 320;
const int REEL_ROLL_W = 120;
const int REEL_MARGIN = 5;
const int SYMBOL_W_H = 100;
const int SYMBOL_MARGIN = 10;
const int REEL_SIZE = 20;
const int MAX_REEL_VELOCITY = 2737;
const int REEL_ACCELERATION = 13687;

enum reelPos { LEFT, MIDDLE, RIGHT };
enum reelStatus { STOPPED, ACCELERATING, MOVING, DECELERATING };

/**
 * @class Scene
 * @brief Implementation of slot machine reel
 */
class Reel{
public:
	Reel(int reelPos);
	~Reel() {};

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
	Uint32 lastFrameTick;
	float currentVelocity;
	int currentSymbolPosition;
	int spinsLeft;
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