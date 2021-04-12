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

	if (Game::getGameState() == FINISHED) {
		int l = leftReel->ready();
		int m = middleReel->ready();
		int r = rightReel->ready();

		if (l == m && m == r) {
			if (DEBUG)
				printf("[SCENE] YOU WON!");
			Game::setCredits(Game::getCredits() + 1000000);
		}
		
		Game::setGameState(READY);
	}

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

/**
 * Safely destroys scene
 */
void Scene::clean() {
	leftReel->clean();
	middleReel->clean();
	rightReel->clean();
	slotScreen->clean();
	userInterface->clean();
}