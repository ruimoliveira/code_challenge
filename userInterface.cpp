#include "userInterface.h"

/**
 * UserInterface constructor
 */
UserInterface::UserInterface() : buttonLock{ -1 } {
	creditsInButton = new Button("assets/creditsIn.png", (int)(WINDOW_W - CREDITS_IN_W - EDGE_MARGIN), EDGE_MARGIN, (int)BUTTON_H, (int)CREDITS_IN_W, CREDITS_IN_BTN);
	creditsOutButton = new Button("assets/creditsOut.png", EDGE_MARGIN, (int)(WINDOW_H - BUTTON_H - EDGE_MARGIN), (int)BUTTON_H, (int)CREDITS_OUT_W, CREDITS_OUT_BTN);
	startButton = new Button("assets/start.png", (int)(WINDOW_W - PLAY_W - EDGE_MARGIN), (int)(WINDOW_H - BUTTON_H - EDGE_MARGIN), (int)BUTTON_H, (int)PLAY_W, START_BTN);
	creditsLabel = new Label();
}

/**
 * Updates UI
 */
void UserInterface::update() {
	buttonLock = creditsInButton->update(buttonLock, false);
	buttonLock = creditsOutButton->update(buttonLock, false);
	buttonLock = startButton->update(buttonLock, true);

	creditsLabel->update();
}

/**
 * Renders UI
 */
void UserInterface::render() {
	creditsInButton->render();
	creditsOutButton->render();
	startButton->render();
	creditsLabel->render();
}

/**
 * Safely deletes UI
 */
void UserInterface::clean() {
	creditsInButton->clean();
	creditsOutButton->clean();
	startButton->clean();
	creditsLabel->clean();
}