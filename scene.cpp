#include "scene.h"

/**
 * Scene constructor
 * @param renderer Target renderer
 */
Scene::Scene(SDL_Renderer * renderer) {
	this->gameRenderer = renderer;
}

/**
 * Builds Scene by initializing and drawing all scene items
 */
void Scene::build() {
	leftReel = new Reel(LEFT);
	middleReel = new Reel(MIDDLE);
	rightReel = new Reel(RIGHT);
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
}