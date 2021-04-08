#include "reel.h"

Reel::Reel(int reelPos) {
	this->shuffle();
	this->pos = reelPos;

	int xPos, yPos;
	switch (reelPos) {
		case LEFT:
			xPos = 0;
			yPos = 0;
			break;
		case MIDDLE:
			xPos = 200;
			yPos = 0;
			break;
		case RIGHT:
			xPos = 400;
			yPos = 0;
			break;
		default:
			xPos = 0;
			yPos = 200;
			break;
	}
}

/**
 * Shuffles slot machine reel
 */
void Reel::shuffle() {
	reelOrder = new int[REEL_SIZE]();
	reelOrder[0] = 17;
	for (int i = 1; i < REEL_SIZE; i++) {
		reelOrder[i] = i;
	}

	std::random_shuffle(&reelOrder[1], &reelOrder[REEL_SIZE]);

	/*TODO: delete printers
	for (int i = 0; i < REEL_SIZE; i++) {
		std::cout << reelOrder[i] << "; ";
	}
	std::cout << std::endl << std::endl;
	*/
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

}