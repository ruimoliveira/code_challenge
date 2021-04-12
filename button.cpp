#include "button.h"

/**
 * Button constructor
 * @param filename Texture filename
 * @param xPosition Position in the X axis
 * @param yPosition Position in the Y axis
 * @param rectH Rectangle height
 * @param rectW Rectangle width
 * @param buttonID Button identifier
 */
Button::Button(const char* filename, int xPosition, int yPosition, int rectH, int rectW, int buttonID)
	: GameObject{ filename, xPosition, yPosition, rectH, rectW }, buttonID{ buttonID }, pressed{ false } {

}

/**
 * Updates button status
 * @param bl Which button is being clicked
 * @param lastButton If this function is checking the last button in the UI
 */
int Button::update(int bl, bool lastButton) {
	int buttonLock = bl;
	if (Game::getMouseState() == MOUSE_DOWN  && (buttonLock == buttonID || buttonLock == -1)) {
		if (checkMouseCollision()) {
			buttonLock = buttonID;

			if (DEBUG)
				printf("[BUTTON] Collision with button %i\n", buttonID);

		} else {
			pressed = false;
			if (lastButton || (buttonLock == buttonID && !pressed)) {
				buttonLock = 0;

				if (DEBUG)
					printf("[BUTTON] No collision\n");
			}
		}
	}

	if (Game::getMouseState() == MOUSE_UP && buttonLock == buttonID) {
		buttonLock = unpressButton(buttonLock);
		action();
	}

	if (Game::getMouseState() == MOUSE_UP && buttonLock == NONE)
		buttonLock = unpressButton(buttonLock);

	return buttonLock;
}

/**
 * Checks for mouse collision
 */
bool Button::checkMouseCollision() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect mouseRect = { x,y,1,1 };


	if (SDL_HasIntersection(&mouseRect, getDestRect())) {
		if (!pressed)
			toggleTexture("2");
		pressed = true;
		return true;
	} else if (pressed) {
		toggleTexture("");
		pressed = false;
	}

	return false;
}

/**
 * Does all unpressing actions
 */
int Button::unpressButton(int bl) {
	int buttonLock = bl;

	Game::setMouseState(MOUSE_IDDLE);
	pressed = false;
	buttonLock = -1;
	
	toggleTexture("");

	return buttonLock;
}

/**
 * Toggles to the other button texture
 * @param str Differentiator string: "" for unpressed, "2" for pressed
 */
void Button::toggleTexture(std::string str) {
	if (Game::getGameState() == READY || buttonID == START_BTN) {
		deleteTexture();
		std::string filename = ASSETS_FOLDER + filenames[buttonID - 1] + str + ASSET_EXTENSION;
		loadTexture(filename.c_str());
	}
}

/**
 * Triggers the button's action 
 */
void Button::action() {
	int credits = Game::getCredits();
	switch (buttonID) {
		case CREDITS_IN_BTN:
			if (Game::getGameState() == READY) {
				if (DEBUG)
					printf("[BUTTON] Credits in activation\n");

				Game::setCredits(++credits);
			}

			break;

		case CREDITS_OUT_BTN:
			if (Game::getGameState() == READY) {
				if (DEBUG)
					printf("[BUTTON] Credits out activation\n");

				Game::setCredits(0);
			}

			break;

		case START_BTN:
			switch (Game::getGameState()) {
				case READY:
					if (DEBUG)
						printf("[BUTTON] Start activation\n");

					if (Game::getCredits() > 0)
						Game::start();
					break;

				case PLAYING:
					Game::setGameState(PAUSED);
					if (DEBUG)
						printf("[BUTTON] Game Paused\n");
					break;

				case PAUSED:
					Game::setGameState(PLAYING);
					if (DEBUG)
						printf("[BUTTON] Game Started\n");
					break;

				default:
					break;
			}
			break;

		default:
			break;
	}
}