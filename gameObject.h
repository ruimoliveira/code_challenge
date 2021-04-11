#ifndef gameObject_h
#define gameObject_h

#include "SDL.h"
#include "SDL_image.h"
#include "game.h"

/**
 * @class GameObject
 * @brief Implementation of generic game object class
 */
class GameObject {
public:
	GameObject(const char* filename, int xPosition, int yPosition, int rectH, int rectW);
	~GameObject() {};

	void loadTexture(const char* filename);
	SDL_Rect * getDestRect();
	int getY();
	void setDestRectY(int y);
	void deleteTexture();
	virtual void update();
	void render();
	void clean();

private:
	int xPosition, yPosition;
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
};

#endif