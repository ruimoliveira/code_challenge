#include "engine.h"

/**
 * Initiates SDL components and engine functions
 */
void Engine::run() {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
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
	window = SDL_CreateWindow("Slot Machine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
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
	SDL_SetRenderDrawColor(game->getRenderer(), 50, 50, 50, 50);
}

/**
 * Runs game loop
 */
void Engine::mainLoop() {
	running = true;

	//initiates FPS cap related 
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	scene = new Scene();

	while (running) {
		frameStart = SDL_GetTicks();

		handleEvents();
		update();
		render();

		//FPS cap
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}
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
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
				game->setMouseState(MOUSE_DOWN);
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
				game->setMouseState(MOUSE_UP);
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

/**
 * Safely exits game, scene and SDL
 */
void Engine::clean() {
	SDL_DestroyWindow(window);
	scene->clean();
	game->clean();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}