#include "gameObject.h"

/**
 * GameObject constructor
 * @param fn Texture filename
 * @param xPos Position in the X axis
 * @param yPos Position in the Y axis
 * @param rectH Rectangle height
 * @param rectW Rectangle width
 */
GameObject::GameObject(const char* fn, int xPos, int yPos, int rectH, int rectW) : xPosition{ xPos }, yPosition{ yPos } {
	loadTexture(fn);

	destRect.h = rectH;
	destRect.w = rectW;
	destRect.x = xPos;
	destRect.y = yPos;
}

/**
 * Destination rect getter
 */
SDL_Rect * GameObject::getDestRect() {
	return &destRect;
}

/**
 * Getter for y axis position
 */
int GameObject::getY() {
	return destRect.y;
}

/**
 * Sets new position for SDL_Rect
 * @param y New y axis coordinate
 */
void GameObject::setDestRectY(int y) {
	destRect.y = y;
}

/**
 * Loads texture from file
 * @param filename Texture filename
 */
void GameObject::loadTexture(const char* filename) {
	SDL_Surface * tempSurface = IMG_Load(filename);
	texture = SDL_CreateTextureFromSurface(Game::getRenderer(), tempSurface);
	SDL_FreeSurface(tempSurface);
}

/**
 * Deletes Texture
 */
void GameObject::deleteTexture() {
	SDL_DestroyTexture(texture);
}

/**
 * Updates Game Object
 */
void GameObject::update() {

}

/**
 * Renders game object
 */
void GameObject::render() {
	SDL_RenderCopy(Game::getRenderer(), texture, NULL, &destRect);
}

/**
 * Deletes self
 */
void GameObject::clean() {
	deleteTexture();
	delete this;
}