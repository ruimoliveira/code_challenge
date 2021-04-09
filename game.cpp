#include "game.h"

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
	window = SDL_CreateWindow("SDL_demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
}

/**
 * Initiates SDL Renderer
 */
void Game::initRenderer() {
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 50);
}

/**
 * Runs game loop
 */
void Game::mainLoop() {
	running = true;

	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	scene = new Scene(renderer);

	gameState = FINISHED;

	while (running) {
		frameStart = SDL_GetTicks();

		handleEvents();
		if (gameState != PAUSED)
			update();
		render();
		
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
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
	scene->update();
}

/**
 * Renders game
 */
void Game::render() {
	SDL_RenderClear(renderer);
	scene->render();
	SDL_RenderPresent(renderer);
}