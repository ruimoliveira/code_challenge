#include "scene.h"

/**
 * Scene constructor
 */
Scene::Scene() {
	leftReel = new Reel(LEFT);
	middleReel = new Reel(MIDDLE);
	rightReel = new Reel(RIGHT);
	slotScreen = new SlotScreen();
	userInterface = new UserInterface();
}

/**
 * Updates scene status
 */
void Scene::update() {
	leftReel->update();
	middleReel->update();
	rightReel->update();
	userInterface->update();
}

/**
 * Renders scene components
 */
void Scene::render() {
	leftReel->render();
	middleReel->render();
	rightReel->render();
	slotScreen->render();
	userInterface->render();
}