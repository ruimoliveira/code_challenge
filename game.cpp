#include "game.h"


SDL_Renderer * Game::renderer = nullptr;
int Game::gameState = FINISHED;
int Game::mouseState = MOUSE_IDDLE;
int Game::credits = 0;

/**
 * Game constructor
 * @param window SDL_Window to create the renderer on
 */
Game::Game(SDL_Window * window) {
	renderer = SDL_CreateRenderer(window, -1, 0);
}

/**
 * Starts game
 */
void Game::start() {

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
 * @returns mouse state
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
 * @returns credit amount
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
 * Safely destroys renderer
 */
void Game::clean() {
	SDL_DestroyRenderer(renderer);
}