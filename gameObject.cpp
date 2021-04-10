#include "gameObject.h"

/**
 * GameObject constructor
 * @param fn Texture filename
 * @param rend Target renderer
 * @param xPos Position in the X axis
 * @param yPos Position in the Y axis
 * @param rectH Rectangle height
 * @param rectW Rectangle width
 */
GameObject::GameObject(const char* fn, SDL_Renderer * rend, int xPos, int yPos, int rectH, int rectW) : renderer{ rend }, xPosition{ xPos }, yPosition{ yPos } {
	loadTexture(fn, rend);

	destRect.h = rectH;
	destRect.w = rectW;
	destRect.x = xPos;
	destRect.y = yPos;
}

/**
 * Renders game object
 */
void GameObject::render() {
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

/**
 * Updates Game Object
 */
void GameObject::update() {

}

/**
 * Loads texture from file
 * @param filename Texture filename
 * @param renderer Target renderer
 * @return Texture
 */
void GameObject::loadTexture(const char* filename, SDL_Renderer * renderer) {
	SDL_Surface * tempSurface = IMG_Load(filename);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	this->texture = texture;
}