#ifndef reel_h
#define reel_h

#include "SDL.h"
#include "gameObject.h"
#include "constants.h"

#include <string>
#include <algorithm>
#include <iostream>
#include <random>

const int REEL_ROLL_H = 320;
const int REEL_ROLL_W = 120;
const int REEL_MARGIN = 5;
const int SYMBOL_W_H = 100;
const int SYMBOL_MARGIN = 10;
const int REEL_SIZE = 20;

enum reelPos { LEFT, MIDDLE, RIGHT };

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

private:
	GameObject * reelBackground;
	GameObject * gameSymbol;
	GameObject * topSymbol;
	GameObject * bottomSymbol;
	int * reelOrder;
	int pos;
	const std::string symbols[20] = { "ace", "apple", "bar", "cherry", "chest",
								 "chip7", "chipspades", "clover", "coin", "diamond",
								 "emerald", "grapes", "horseshoe", "jack", "king",
								 "nine", "queen", "seven", "shield", "watermelon" };

	void shuffle();
	void initGameObjects(int xPos, int yPos);
};

#endif