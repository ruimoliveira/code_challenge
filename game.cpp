#include "game.h"


SDL_Renderer * Game::renderer = nullptr;
int Game::gameState = FINISHED;

/**
 * Game constructor
 * @param window SDL_Window to create the renderer on
 */
Game::Game(SDL_Window * window) {
	renderer = SDL_CreateRenderer(window, -1, 0);
}

/**
 * Renderer Getter
 * @returns Renderer
 */
SDL_Renderer * Game::getRenderer() {
	return renderer;
}

/**
 * Game State getter
 * @returns gameState
 */
int Game::getGameState() {
	return gameState;
}

/**
 * Game State setter
 * @param gs New gamestate to set to
 */
void Game::setGameState(int gs) {
	gameState = gs;
}

/**
 * Safely destroys renderer
 */
void Game::clean() {
	SDL_DestroyRenderer(renderer);
}