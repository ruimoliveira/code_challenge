#include "text.h"

/**
 * Text constructor
 * @param filename Text counter ID
 */
Text::Text(int textID) : textID{ textID }, counter{ 0 }, credits{ 0 } {
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

	font = TTF_OpenFont("assets/arial.ttf", FONT_SIZE);
	addToCounter(counter);
}

/**
 * Adds a certain quantity to the counter
 * @param qt Quantity to add
 */
void Text::addToCounter(int qt) {
	counter = counter + qt;
	if (DEBUG)
		printf("[TEXT %i] Counter = %i\n", textID, counter);

	std::string textToDisplay = text + std::to_string(counter);
	loadTexture(textToDisplay.c_str());

	updateTexture();
}

/**
 * Loads texture
 * @param text Text to display
 */
void Text::loadTexture(const char* text) {
	clean();
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface * tempSurface = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(Game::getRenderer(), tempSurface);
	SDL_FreeSurface(tempSurface);
}

/**
 * Updates texture
 */
void Text::updateTexture() {
	SDL_QueryTexture(texture, nullptr, nullptr, &destRect.w, &destRect.h);

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
 * Renders Text
 */
void Text::render() {
	SDL_RenderCopy(Game::getRenderer(), texture, NULL, &destRect);
}

/**
 * Updates Text
 */
void Text::update() {
	if (Game::getCredits() != credits) {
		switch (textID) {
		case TEXT_CREDITS_INSERTED:
			if (Game::getCredits() == credits + 1)
				addToCounter(1);
			break;

		case TEXT_CREDITS_TAKEN:
			if (Game::getCredits() == 0 && Game::getGameState() == READY) {
				if (DEBUG)
					printf("[TEXT %i] getGameState = %i\n", textID,Game::getGameState());

				addToCounter(credits);
			}
			break;
		}

		credits = Game::getCredits();
	}
}

/**
 * Cleans Text for deletion
 */
void Text::clean() {
	SDL_DestroyTexture(texture);
}