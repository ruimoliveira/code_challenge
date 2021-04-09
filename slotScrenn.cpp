#include "slotScreen.h"

/**
 * SlotScreen constructor
 * @param renderer Target renderer
 */
SlotScreen::SlotScreen(SDL_Renderer * rend) {
	renderer = rend;

	topPanel = new GameObject("assets/blackBCKGRD.png", renderer, 0, 0, ((WINDOW_H - SCREEN_H) / 2), WINDOW_W);
	leftPanel = new GameObject("assets/blackBCKGRD.png", renderer, 0, ((WINDOW_H - SCREEN_H) / 2), SCREEN_H, ((WINDOW_W - SCREEN_W) / 2));
	rightPanel = new GameObject("assets/blackBCKGRD.png", renderer, (WINDOW_W - (WINDOW_W - SCREEN_W) / 2), ((WINDOW_H - SCREEN_H) / 2), SCREEN_H, ((WINDOW_W - SCREEN_W) / 2));
	bottomPanel = new GameObject("assets/blackBCKGRD.png", renderer, 0, (WINDOW_H - (WINDOW_H - SCREEN_H) / 2), ((WINDOW_H - SCREEN_H) / 2), WINDOW_W);
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