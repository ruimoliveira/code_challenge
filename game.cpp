#include "game.h"


SDL_Renderer * Game::renderer = nullptr;
int Game::gameState = READY;
int Game::mouseState = MOUSE_IDDLE;
int Game::credits = 0;
int Game::gameResult[] = {0, 0, 0};

/**
 * Game constructor
 * @param window SDL_Window to create the renderer on
 */
Game::Game(SDL_Window * window) {
	renderer = SDL_CreateRenderer(window, -1, 0);
	credits = 0;
}

/**
 * Starts game
 */
void Game::start() {
	//applies playing tax
	credits--;

	computeResult();
	gameState = PLAYING;
	if (DEBUG)
		printf("[GAME] gameState : %i\n", gameState);
}

/**
 * Randomizes final reel position for each reel and stores on gameResult
 */
void Game::computeResult() {
	srand(time(NULL));
	for (int i = 0; i < N_REELS; i++) {
		gameResult[i] = rand() % 20;
	}

	if (DEBUG)
		printf("[GAME] Reel final positions: { %i, %i, %i }\n", gameResult[0], gameResult[1], gameResult[2]);
}

/**
 * Renderer getter
 * @returns Renderer
 */
SDL_Renderer * Game::getRenderer() {
	return renderer;
}

/**
 * Game state getter
 * @returns gameState
 */
int Game::getGameState() {
	return gameState;
}

/**
 * Game state setter
 * @param gs New gamestate to set to
 */
void Game::setGameState(int gs) {
	gameState = gs;
}

/**
 * Mouse state getter
 * @returns mouseState
 */
int Game::getMouseState() {
	return mouseState;
}

/**
 * Mouse state setter
 * @param ms New mouse state to set to
 */
void Game::setMouseState(int ms) {
	mouseState = ms;
}

/**
 * Credit amount getter
 * @returns credits
 */
int Game::getCredits() {
	return credits;
}

/**
 * Credit amount setter
 * @param c New credit amount
 */
void Game::setCredits(int c) {
	credits = c;
}

/**
 * Getter for the final reel symbol to display
 * @returns symbol's reel position
 */
int Game::getGameResult(int reelPosition) {
	return gameResult[reelPosition];
}

/**
 * Safely destroys renderer
 */
void Game::clean() {
	SDL_DestroyRenderer(renderer);
}