#ifndef slotScreen_h
#define slotScreen_h

#include "SDL.h"
#include "gameObject.h"
#include "constants.h"

const int SCREEN_W = 400;
const int SCREEN_H = 200;

/**
 * @class SlotScreen
 * @brief Implementation of slot machine screen
 */
class SlotScreen {
public:
	SlotScreen(SDL_Renderer * renderer);
	~SlotScreen() {};

	void render();

private:
	GameObject * topPanel;
	GameObject * bottomPanel;
	GameObject * leftPanel;
	GameObject * rightPanel;
};

#endif