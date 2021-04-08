#include "scene.h"

void Scene::build() {
	shuffleReels();
}

/**
 * Loads texture from file
 * @param filename Texture filename
 * @param renderer Target renderer
 * @return Texture
 */
SDL_Texture* Scene::loadTexture(const char* filename, SDL_Renderer * renderer) {
	SDL_Surface * tempSurface = IMG_Load(filename);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return texture;
}

/**
 * Shuffles slot machine reels 
 */
void Scene::shuffleReels() {
	leftReel = new int[REEL_SIZE]();
	shuffle(leftReel);
	middleReel = new int[REEL_SIZE]();
	shuffle(middleReel);
	rightReel = new int[REEL_SIZE]();
	shuffle(rightReel);

	/*TODO: delete printers
	for (int i = 0; i < REEL_SIZE; i++) {
		std::cout << leftReel[i] << "; ";
	}
	std::cout << std::endl << std::endl;

	for (int i = 0; i < REEL_SIZE; i++) {
		std::cout << middleReel[i] << "; ";
	}
	std::cout << std::endl << std::endl;

	for (int i = 0; i < REEL_SIZE; i++) {
		std::cout << rightReel[i] << "; ";
	}
	std::cout << std::endl << std::endl;
	*/
}

/**
 * Shuffles a single reel
 * @param reel Reel to shuffle
 */
void Scene::shuffle(int * reel) {
	reel[0] = 17;
	for (int i = 1; i < REEL_SIZE; i++) {
		reel[i] = i;
	}

	std::random_shuffle(&reel[1], &reel[REEL_SIZE]);
}