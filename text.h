#ifndef text_h
#define text_h

#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#else
#include <SDL.h>
#include <SDL_ttf.h>
#endif

#include <string>

#include "constants.h"
#include "game.h"

enum textIDs { TEXT_CREDITS_INSERTED, TEXT_CREDITS_TAKEN, TEXT_PLAY_COUNTER };
const std::string C_I = "Credits inserted: ";
const std::string C_T = "Credits taken: ";
const std::string P_C = "Play counter: ";
const int FONT_SIZE = 16;

/*
 * @class Text
 * @brief Bundles counters display text
 */
class Text {
public:
	Text(int textID);
	~Text() {};

	void addToCounter(int qt);
	void loadTexture(const char* text);
	void updateTexture();
	void render();
	void update();
	void clean();

private:
	int textID;
	int counter;
	int credits;
	std::string text;
	TTF_Font * font;
	SDL_Texture * texture;
	SDL_Rect destRect;
};

#endif
