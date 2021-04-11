#ifndef slotScreen_h
#define slotScreen_h

#include "SDL.h"
#include "gameObject.h"
#include "constants.h"

const int SCREEN_W = 400;
const int SCREEN_H = 220;

/**
 * @class SlotScreen
 * @brief Implementation of slot machine screen
 */
class SlotScreen {
public:
	SlotScreen();
	~SlotScreen() {};

	void render();
	void clean();

private:
	GameObject * topPanel;
	GameObject * bottomPanel;
	GameObject * leftPanel;
	GameObject * rightPanel;
};

#endif