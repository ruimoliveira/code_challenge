#include "reel.h"

/**
 * Reel constructor
 * @param reelPos Reel position
 * @param renderer Target renderer
 */
Reel::Reel(int reelPos, SDL_Renderer * renderer) {
	this->shuffle();
	this->pos = reelPos;

	int xPos, yPos;
	switch (reelPos) {
		case LEFT:
			xPos = (WINDOW_W - REEL_ROLL_W * 3 - REEL_MARGIN * 2 ) / 2;
			yPos = (WINDOW_H - REEL_ROLL_H) / 2;
			break;
		case MIDDLE:
			xPos = (WINDOW_W - REEL_ROLL_W * 3 - REEL_MARGIN * 2) / 2 + REEL_ROLL_W + REEL_MARGIN;
			yPos = (WINDOW_H - REEL_ROLL_H) / 2;
			break;
		case RIGHT:
			xPos = (WINDOW_W - REEL_ROLL_W * 3 - REEL_MARGIN * 2) / 2 + (REEL_ROLL_W + REEL_MARGIN) * 2;
			yPos = (WINDOW_H - REEL_ROLL_H) / 2;
			break;
		default:
			xPos = 0;
			yPos = 0;
			break;
	}

	initGameObjects(renderer, xPos, yPos);
}

/**
 * Shuffles slot machine reel
 */
void Reel::shuffle() {
	reelOrder = new int[REEL_SIZE]();
	reelOrder[0] = 17;
	for (int i = 1; i < 18; i++) {
		reelOrder[i] = i-1;
	}
	for (int i = 18; i < REEL_SIZE; i++) {
		reelOrder[i] = i;
	}

	std::shuffle(&reelOrder[1], &reelOrder[REEL_SIZE], std::default_random_engine(std::random_device()()));

	/*TODO: delete printers
	for (int i = 0; i < REEL_SIZE; i++) {
		std::cout << reelOrder[i] << "; ";
	}
	std::cout << std::endl << std::endl;
	*/
}

/**
 * Initiates game objects associated with a reel
 * @param renderer Target renderer
 * @param xPos Position of the reel in the X axis
 * @param yPos Position of the reel in the Y axis
 */
void Reel::initGameObjects(SDL_Renderer * renderer, int xPos, int yPos) {
	reelBackground = new GameObject("assets/whiteBCKGRD.png", renderer, xPos, yPos, REEL_ROLL_H, REEL_ROLL_W);

	std::string filename = ASSETS_FOLDER + symbols[reelOrder[0]] + ASSET_EXTENSION;
	gameSymbol = new GameObject(&filename[0], renderer, xPos + ((REEL_ROLL_W - SYMBOL_W_H) / 2), yPos + (SYMBOL_W_H + SYMBOL_MARGIN), SYMBOL_W_H, SYMBOL_W_H);

	filename = ASSETS_FOLDER + symbols[reelOrder[REEL_SIZE - 1]] + ASSET_EXTENSION;
	topSymbol = new GameObject(&filename[0], renderer, xPos + ((REEL_ROLL_W - SYMBOL_W_H) / 2), yPos, SYMBOL_W_H, SYMBOL_W_H);

	filename = ASSETS_FOLDER + symbols[reelOrder[1]] + ASSET_EXTENSION;
	bottomSymbol = new GameObject(&filename[0], renderer, xPos + ((REEL_ROLL_W - SYMBOL_W_H) / 2), yPos + ((SYMBOL_W_H + SYMBOL_MARGIN) * 2), SYMBOL_W_H, SYMBOL_W_H);
}

/**
 * Updates slot machine reel
 */
void Reel::update() {

}

/**
 * Renders slot machine reel
 */
void Reel::render() {
	reelBackground->render();
	gameSymbol->render();
	topSymbol->render();
	bottomSymbol->render();
}