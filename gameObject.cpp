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
GameObject::GameObject(const char* fn, SDL_Renderer * rend, int xPos, int yPos, int rectH, int rectW) {
	this->renderer = rend;

	loadTexture(fn, rend);

	this->xPosition = xPos;
	this->yPosition = yPos;

	this->srcRect.h = rectH;
	this->srcRect.w = rectW;
	this->srcRect.x = xPos;
	this->srcRect.y = yPos;

	this->destRect.h = rectH;
	this->destRect.w = rectW;
	this->destRect.x = xPos;
	this->destRect.y = yPos;
}

/**
 * Renders game object
 */
void GameObject::render() {
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
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