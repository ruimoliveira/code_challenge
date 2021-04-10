#include "userInterface.h"

UserInterface::UserInterface(SDL_Renderer * renderer) {
	creditsInButton = new Button("assets/creditsIn.png", renderer, WINDOW_W - (int)CREDITS_IN_W - EDGE_MARGIN, EDGE_MARGIN, (int)BUTTON_H, (int)CREDITS_IN_W, CREDITS_IN);
	creditsOutButton = new Button("assets/creditsOut.png", renderer, EDGE_MARGIN, WINDOW_H - (int)BUTTON_H - EDGE_MARGIN, (int)BUTTON_H, (int)CREDITS_OUT_W, CREDITS_OUT);
	startButton = new Button("assets/play.png", renderer, WINDOW_W - (int)PLAY_W - EDGE_MARGIN, WINDOW_H - (int)BUTTON_H - EDGE_MARGIN, (int)BUTTON_H, (int)PLAY_W, START);
}

void UserInterface::render() {
	creditsInButton->render();
	creditsOutButton->render();
	startButton->render();
}

void UserInterface::update() {
	creditsInButton->update();
	creditsOutButton->update();
	startButton->update();
}