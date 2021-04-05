#include "game.h"

Game::Game() {}

Game::~Game() {}

/**
 * Initiates SDL and game functions
 */
void Game::run() {
	SDL_Init(SDL_INIT_EVERYTHING);
	initWindow();
	initRenderer();
	mainLoop();
	clean();
}

/**
 * Initiates SDL Window
 */
void Game::initWindow() {
	window = SDL_CreateWindow("SDL_demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
}

/**
 * Initiates SDL Renderer
 */
void Game::initRenderer() {
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

/**
 * Runs game loop
 */
void Game::mainLoop() {
	running = true;

	while (running) {
		handleEvents();
		update();
		render();
	}
}

/**
 * Safely exits SDL
 */
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

/**
 * Handles input events
 */
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;

		default:
			break;
	}
}

/**
 * Updates game status
 */
void Game::update() {
	count == 0;
	count++;
	std::cout << count << std::endl;
}

/**
 * Renders game
 */
void Game::render() {
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}