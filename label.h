#ifndef label_h
#define label_h

#include "SDL.h"
#include "gameObject.h"
#include "constants.h"
#include "game.h"

#include <map>
#include <iostream>
#include <string>

const float LABEL_W = 55 * UI_SCALE;
const float LABEL_H = 71 * UI_SCALE;
const float LOGO_MARGIN = 25 * UI_SCALE;

/**
 * @class Label
 * @brief Bundles credits' label objects
 */
class Label {
public:
	Label();
	~Label() {};

	void update();
	void render();
	void clean();

private:
	int credits;
	std::map<int, GameObject*> label;

	void addLogo();
	void newNumber();
};

#endif