#include "reel.h"

/**
 * Reel constructor
 * @param reelPos Reel position
 */
Reel::Reel(int reelPos) : position{ reelPos }, status{ STOPPED }, currentVelocity{ 0 } {
	shuffle();
	display();
}

/**
 * Shuffles slot machine reel putting always number 7 in first place
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

	if (DEBUG) {
		printf("[REEL] Reel %i:\n\t", position);
		for (int i = 0; i < REEL_SIZE; i++)
			printf("%i; ", reelOrder[i]);
		printf("\n");
	}
}

/**
 * Displays reel one the screen
 */
void Reel::display() {
	int yPos = (WINDOW_H - REEL_ROLL_H) / 2;
	spinsLeft = position + 1;

	initGameObjects(getX(), yPos);
	lastFrameTick = SDL_GetTicks();
}

/**
 * Initiates game objects associated with a reel
 * @param xPos Position of the reel in the X axis
 * @param yPos Position of the reel in the Y axis
 */
void Reel::initGameObjects(int xPos, int yPos) {
	reelBackground = new GameObject("assets/whiteBCKGRD.png", xPos, yPos, REEL_ROLL_H, REEL_ROLL_W);

	currentSymbolPosition = 0;
	std::string filename = ASSETS_FOLDER + symbols[reelOrder[0]] + ASSET_EXTENSION;
	gameSymbol = new GameObject(&filename[0], xPos + ((REEL_ROLL_W - SYMBOL_W_H) / 2), yPos + (SYMBOL_W_H + SYMBOL_MARGIN), SYMBOL_W_H, SYMBOL_W_H);

	filename = ASSETS_FOLDER + symbols[reelOrder[REEL_SIZE - 1]] + ASSET_EXTENSION;
	topSymbol = new GameObject(&filename[0], xPos + ((REEL_ROLL_W - SYMBOL_W_H) / 2), yPos, SYMBOL_W_H, SYMBOL_W_H);

	filename = ASSETS_FOLDER + symbols[reelOrder[1]] + ASSET_EXTENSION;
	bottomSymbol = new GameObject(&filename[0], xPos + ((REEL_ROLL_W - SYMBOL_W_H) / 2), yPos + ((SYMBOL_W_H + SYMBOL_MARGIN) * 2), SYMBOL_W_H, SYMBOL_W_H);
}

/**
 * Updates slot machine reel
 */
void Reel::roll(int distance) {
	if (spinsLeft > 0 && currentSymbolPosition != REEL_SIZE - 1) {
		if (!displayingTopSymbol()) {
			swapSymbols();
		} else {
			gameSymbol->setDestRectY(gameSymbol->getY() - distance);
			topSymbol->setDestRectY(topSymbol->getY() - distance);
			bottomSymbol->setDestRectY(bottomSymbol->getY() - distance);
		}
	}
}

/**
 * Checks for collision bewteen middle symbol and top screen panel
 */
bool Reel::displayingTopSymbol() {
	int y = ((WINDOW_H - SCREEN_H) / 2);
	SDL_Rect displayTopPanel = { getX() + SYMBOL_W_H / 2 ,y,1,1 };

	//if gameSymbol and the top panel are colliding, then the top symbol is hidden and can be swapped
	if (SDL_HasIntersection(&displayTopPanel, gameSymbol->getDestRect()))
		return false;

	return true;
}

/**
 * Updates slot machine reel
 */
void Reel::swapSymbols() {
	topSymbol->deleteTexture();
	topSymbol = gameSymbol;

	gameSymbol = bottomSymbol;

	int nextSymbol = currentSymbolPosition++ + 2;
	if (nextSymbol >= 20) {
		nextSymbol = nextSymbol - 20;
	}
	std::string filename = ASSETS_FOLDER + symbols[reelOrder[nextSymbol]] + ASSET_EXTENSION;
	bottomSymbol = new GameObject(&filename[0], (getX() + ((REEL_ROLL_W - SYMBOL_W_H) / 2)), (gameSymbol->getY() + SYMBOL_W_H + SYMBOL_MARGIN), SYMBOL_W_H, SYMBOL_W_H);

	if (currentSymbolPosition == REEL_SIZE - 1)
		spinsLeft--;
}

/**
 * Getter for X axis position for this reel's textures
 */
int Reel::getX() {
	int x;
	switch (position) {
		case LEFT:
			x = (WINDOW_W - REEL_ROLL_W * 3 - REEL_MARGIN * 2) / 2;
			break;

		case MIDDLE:
			x = (WINDOW_W - REEL_ROLL_W * 3 - REEL_MARGIN * 2) / 2 + REEL_ROLL_W + REEL_MARGIN ;
			break;

		case RIGHT:
			x = (WINDOW_W - REEL_ROLL_W * 3 - REEL_MARGIN * 2) / 2 + (REEL_ROLL_W + REEL_MARGIN) * 2;
			break;
	}
	return x;
}

/**
 * Updates slot machine reel
 */
void Reel::update() {
	if (Game::getGameState() == PLAYING) {
		float frameTime = (float)(SDL_GetTicks() - lastFrameTick)/1000;
		float distance = 0;
		switch (status) {
			case STOPPED:
				status = ACCELERATING;
			case ACCELERATING:
				currentVelocity = currentVelocity + REEL_ACCELERATION * frameTime;
				if (currentVelocity > MAX_REEL_VELOCITY) {
					status = MOVING;
					currentVelocity = MAX_REEL_VELOCITY;
				}

				distance = (int)(currentVelocity * frameTime + 0.5 * REEL_ACCELERATION * frameTime * frameTime);
				roll(distance);
				break;

			case MOVING:
				distance = (int)(currentVelocity * frameTime);
				roll(distance);
				break;

			case DECELERATING:
				break;
		}
	}
	
	lastFrameTick = SDL_GetTicks();
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

/**
 * Safely deletes slot machine reel
 */
void Reel::clean() {
	reelBackground->clean();
	gameSymbol->clean();
	topSymbol->clean();
	bottomSymbol->clean();
}