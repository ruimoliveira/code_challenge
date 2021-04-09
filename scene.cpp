#include "scene.h"

/**
 * Scene constructor
 * @param renderer Target renderer
 */
Scene::Scene(SDL_Renderer * renderer) {
	leftReel = new Reel(LEFT, renderer);
	middleReel = new Reel(MIDDLE, renderer);
	rightReel = new Reel(RIGHT, renderer);
	slotScreen = new SlotScreen(renderer);
}

/**
 * Updates scene status
 */
void Scene::update() {
	leftReel->update();
	middleReel->update();
	rightReel->update();
}

/**
 * Renders scene components
 */
void Scene::render() {
	leftReel->render();
	middleReel->render();
	rightReel->render();
	slotScreen->render();
}