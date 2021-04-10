#include "engine.h"

/**
 * Initiates SDL and engine functions
 */
void Engine::run() {
	SDL_Init(SDL_INIT_EVERYTHING);
	initWindow();
	initGame();
	initRenderer();
	mainLoop();
	clean();
}

/**
 * Initiates SDL Window
 */
void Engine::initWindow() {
	window = SDL_CreateWindow("SDL_demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
}

/**
 * Initiates SDL Renderer
 */
void Engine::initGame() {
	game = new Game(window);
}


/**
 * Initiates SDL Renderer
 */
void Engine::initRenderer() {
	SDL_SetRenderDrawColor(Game::getRenderer(), 50, 50, 50, 50);
}

/**
 * Runs game loop
 */
void Engine::mainLoop() {
	running = true;

	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	scene = new Scene();

	while (running) {
		frameStart = SDL_GetTicks();

		handleEvents();
		if (game->getGameState() != PAUSED)
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
void Engine::clean() {
	SDL_DestroyWindow(window);
	game->clean();
	SDL_Quit();
}

/**
 * Handles input events
 */
void Engine::handleEvents() {
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
void Engine::update() {
	scene->update();
}

/**
 * Renders game
 */
void Engine::render() {
	SDL_RenderClear(Game::getRenderer());
	scene->render();
	SDL_RenderPresent(Game::getRenderer());
}