#include "userInterface.h"

/**
 * UserInterface constructor
 */
UserInterface::UserInterface() {
	creditsInButton = new Button("assets/creditsIn.png", (int)(WINDOW_W - CREDITS_IN_W - EDGE_MARGIN), EDGE_MARGIN, (int)BUTTON_H, (int)CREDITS_IN_W, CREDITS_IN);
	creditsOutButton = new Button("assets/creditsOut.png", EDGE_MARGIN, (int)(WINDOW_H - BUTTON_H - EDGE_MARGIN), (int)BUTTON_H, (int)CREDITS_OUT_W, CREDITS_OUT);
	startButton = new Button("assets/play.png", (int)(WINDOW_W - PLAY_W - EDGE_MARGIN), (int)(WINDOW_H - BUTTON_H - EDGE_MARGIN), (int)BUTTON_H, (int)PLAY_W, START);
	creditsLabel = new Label();
}

/**
 * Updates UI
 */
void UserInterface::update() {
	creditsInButton->update();
	creditsOutButton->update();
	startButton->update();
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