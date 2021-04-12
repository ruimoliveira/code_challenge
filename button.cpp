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
 * @param mouseLock Which button is being clicked
 * @param lastButton Signals if this function is checking the last button in the UI
 * @returns NONE if !checkMouseCollision(), buttonID if checkMouseCollision()
 */
int Button::update(int mouseLock, bool lastButton) {
	if (Game::getMouseState() == MOUSE_DOWN  && (mouseLock == buttonID || mouseLock == -1)) {
		if (checkMouseCollision()) {
			// Signals that button is being pressed
			mouseLock = buttonID;

			if (DEBUG)
				printf("[BUTTON] Collision with button %i\n", buttonID);
		} else {
			// Signals that button it not being pressed
			if (lastButton || (mouseLock == buttonID && !pressed)) {
				mouseLock = NONE;

				if (DEBUG)
					printf("[BUTTON] No collision\n");
			}
		}
	}

	// Actions the button if mouse never stopped colliding with button
	if (Game::getMouseState() == MOUSE_UP && mouseLock == buttonID)
		action();

	// Unpresses button
	if (Game::getMouseState() == MOUSE_UP && (mouseLock == NONE || mouseLock == buttonID))
		mouseLock = unpressButton(mouseLock);

	return mouseLock;
}

/**
 * Checks for mouse collision
 */
bool Button::checkMouseCollision() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Rect mouseRect = { x,y,1,1 };

	if (SDL_HasIntersection(&mouseRect, getDestRect())) {
		// Signals that button and mouse are colliding
		if (!pressed)
			toggleTexture("2");
		pressed = true;
		return true;
	} else if (pressed) {
		// Signals that button and mouse are not colliding
		toggleTexture("");
		pressed = false;
	}

	return false;
}

/**
 * Reverts button and mouse to initial state
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
	// Start button can toggle any time
	// Other button only toggle when the game is not running
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
					// Starts game if it has enough credits
					if (Game::getCredits() > 0)
						Game::start();
					break;

				case PLAYING:
					// Pauses game
					Game::setGameState(PAUSED);
					if (DEBUG)
						printf("[BUTTON] Game Paused\n");
					break;

				case PAUSED:
					// Unpauses game
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