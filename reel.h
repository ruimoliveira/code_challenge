#ifndef reel_h
#define reel_h

#include "SDL.h"
#include "gameObject.h"

#include <string>
#include <algorithm>
#include <iostream>

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
	int * reelOrder;
	int pos;
	const int REEL_SIZE = 20;
	const std::string symbols[20] = { "ace", "apple", "bar", "cherry", "chest",
								 "chip7", "chipspades", "clover", "coin", "diamond",
								 "emerald", "grapes", "horseshoe", "jack", "king",
								 "nine", "queen", "seven", "shield", "watermelon" };

	void shuffle();
};

#endif