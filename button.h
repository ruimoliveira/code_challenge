#ifndef button_h
#define button_h

#include "SDL.h"
#include "gameObject.h"
#include "constants.h"

enum buttonIDs { CREDITS_IN, CREDITS_OUT, START };

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
	Button(const char* filename, SDL_Renderer * renderer, int xPosition, int yPosition, int rectH, int rectW, int buttonID);
	~Button() {};

	void update() override;
private:
	void action();
};

#endif