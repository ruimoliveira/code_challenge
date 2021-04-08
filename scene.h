#ifndef scene_h
#define scene_h

#include "SDL.h"
#include "SDL_image.h"

#include <string>
#include <algorithm>
#include <iostream>

class Scene {
public:
	Scene() {};
	~Scene() {};

	void build();

private:
	const std::string symbols[20] = { "ace", "apple", "bar", "cherry", "chest",
								 "chip7", "chipspades", "clover", "coin", "diamond",
								 "emerald", "grapes", "horseshoe", "jack", "king",
								 "nine", "queen", "seven", "shield", "watermelon" };
	const int REEL_SIZE = 20;

	int * rightReel;
	int * middleReel;
	int * leftReel;

	void shuffleReels();
	void shuffle(int * reel);
	void draw();
	SDL_Texture* loadTexture(const char* filename, SDL_Renderer * renderer);
};

#endif