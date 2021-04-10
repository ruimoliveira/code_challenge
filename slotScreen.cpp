#include "slotScreen.h"

/**
 * SlotScreen constructor
 */
SlotScreen::SlotScreen() {
	topPanel = new GameObject("assets/blackBCKGRD.png", 0, 0, ((WINDOW_H - SCREEN_H) / 2), WINDOW_W);
	leftPanel = new GameObject("assets/blackBCKGRD.png", 0, ((WINDOW_H - SCREEN_H) / 2), SCREEN_H, ((WINDOW_W - SCREEN_W) / 2));
	rightPanel = new GameObject("assets/blackBCKGRD.png", (WINDOW_W - (WINDOW_W - SCREEN_W) / 2), ((WINDOW_H - SCREEN_H) / 2), SCREEN_H, ((WINDOW_W - SCREEN_W) / 2));
	bottomPanel = new GameObject("assets/blackBCKGRD.png", 0, (WINDOW_H - (WINDOW_H - SCREEN_H) / 2), ((WINDOW_H - SCREEN_H) / 2), WINDOW_W);
}

/**
 * Renders slot machine reel
 */
void SlotScreen::render() {
	topPanel->render();
	leftPanel->render();
	rightPanel->render();
	bottomPanel->render();
}