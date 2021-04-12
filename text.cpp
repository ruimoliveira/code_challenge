#include "text.h"

/**
 * Text constructor
 * @param filename Text counter ID
 */
Text::Text(int textID) : textID{ textID }, counter { 0 } {
	switch (textID) {
		case TEXT_CREDITS_INSERTED:
			text = C_I;
			break;
		case TEXT_CREDITS_TAKEN:
			text = C_T;
			break;
		case TEXT_PLAY_COUNTER:
			text = P_C;
			break;
	}

	std::string textToDisplay = text + std::to_string(counter);
	loadTexture(textToDisplay.c_str());

	SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);
	update();
}

/**
 * Adds a certain quantity to the counter
 * @param qt Quantity to add
 */
void Text::addToCounter(int qt) {
	counter = counter + qt;
	if (DEBUG)
		printf("[TEXT %i] Counter = %i\n", textID, counter);
	SDL_DestroyTexture(texture);

	std::string textToDisplay = text + std::to_string(counter);
	loadTexture(textToDisplay.c_str());
}

/**
 * Loads texture
 * @param text Text to display
 */
void Text::loadTexture(const char* text) {
	TTF_Font *font = TTF_OpenFont("assets/arial.ttf", FONT_SIZE);
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface * tempSurface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(Game::getRenderer(), tempSurface);
	SDL_FreeSurface(tempSurface);
}

/**
 * Renders Text
 */
void Text::render() {
	SDL_RenderCopy(Game::getRenderer(), texture, NULL, &destRect);
}

/**
 * Updates Text
 */
void Text::update() {
	int xPos = WINDOW_W / 2 - destRect.w / 2, yPos;
	switch (textID) {
	case TEXT_CREDITS_INSERTED:
		yPos = WINDOW_H - EDGE_MARGIN * 2 - destRect.h * 2;
		break;
	case TEXT_CREDITS_TAKEN:
		yPos = WINDOW_H - EDGE_MARGIN * 2 - destRect.h;
		break;
	case TEXT_PLAY_COUNTER:
		yPos = WINDOW_H - EDGE_MARGIN * 2;
		break;
	}
	destRect.x = xPos;
	destRect.y = yPos;
}

/**
 * Cleans Text for deletion
 */
void Text::clean() {
	SDL_DestroyTexture(texture);
}