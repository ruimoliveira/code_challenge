#ifndef gameObject_h
#define gameObject_h

#include "SDL.h"
#include "SDL_image.h"

/**
 * @class GameObject
 * @brief Implementation of generic game object class
 */
class GameObject {
public:
	GameObject(const char* filename, SDL_Renderer * renderer, int xPosition, int yPosition, int rectH, int rectW);
	~GameObject() {};

	void loadTexture(const char* filename, SDL_Renderer * renderer);
	void update();
	void render();

private:
	int xPosition, yPosition;
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer * renderer;

};

#endif