#ifndef button_h
#define button_h

#include "SDL.h"
#include "gameObject.h"
#include "constants.h"
#include "game.h"

#include <stdio.h>
#include <iostream>
#include <string>

enum buttonIDs { NONE = 0, CREDITS_IN = 1, CREDITS_OUT = 2, START = 3 };

const float BUTTON_H = 65 * UI_SCALE;
const float PLAY_W = 211 * UI_SCALE;
const float CREDITS_IN_W = 472 * UI_SCALE;
const float CREDITS_OUT_W = 530 * UI_SCALE;

/**
 * @class Button
 * @brief Button class that extends GameObject
 */
class Button : public GameObject{
public:
	Button(const char* filename, int xPosition, int yPosition, int rectH, int rectW, int buttonID);
	~Button() {};

	int update(int buttonLock, bool lastButton);

private:
	int buttonID;
	bool pressed;
	const std::string filenames[3] = { "creditsIn", "creditsOut", "start" };

	void action();
	bool checkMouseCollision();
	int unpressButton(int buttonLock);
	void toggleTexture(std::string str);
};

#endif