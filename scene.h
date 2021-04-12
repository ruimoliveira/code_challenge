#ifndef scene_h
#define scene_h

#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif

#include "reel.h"
#include "slotScreen.h"
#include "userInterface.h"
#include "game.h"
#include "text.h"

/**
 * @class Scene
 * @brief Implementation of scene related functionality such as drawing
 * and destroying game objects.
 */
class Scene {
public:
	Scene();
	~Scene() {};

	void update();
	void render();
	void clean();

private:
	Reel * leftReel;
	Reel * middleReel;
	Reel * rightReel;
	SlotScreen * slotScreen;
	UserInterface * userInterface;
	Text * creditsInCounter;
	Text * creditsOutCounter;
	Text * playCounter;
};

#endif