#ifndef scene_h
#define scene_h

#include "SDL.h"
#include "SDL_image.h"
#include "reel.h"
#include "slotScreen.h"
#include "userInterface.h"

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

private:
	Reel * leftReel;
	Reel * middleReel;
	Reel * rightReel;
	SlotScreen * slotScreen;
	UserInterface * userInterface;
};

#endif