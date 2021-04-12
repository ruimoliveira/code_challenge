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
	creditsInCounter = new Text(TEXT_CREDITS_INSERTED);
	creditsOutCounter = new Text(TEXT_CREDITS_TAKEN);
	playCounter = new Text(TEXT_PLAY_COUNTER);
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
				printf("[SCENE] YOU WON %i CREDITS!\n", CREDITS_PRIZE);
			Game::setCredits(Game::getCredits() + CREDITS_PRIZE);
		}
		
		Game::setGameState(READY);
		if (DEBUG)
			printf("[SCENE] Game Ready\n");
		playCounter->addToCounter(1);
	}

	userInterface->update();
	creditsInCounter->update();
	creditsOutCounter->update();
	playCounter->update();
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
	creditsInCounter->render();
	creditsOutCounter->render();
	playCounter->render();
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
	creditsInCounter->clean();
	creditsOutCounter->clean();
	playCounter->clean();
}