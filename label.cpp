#include "label.h"

/**
 * Label constructor
 */
Label::Label() : credits{ 0 } {
	addLogo();
	newNumber();
}

/**
 * Adds credits logo to the label
 */
void Label::addLogo() {
	label[0] = new GameObject("assets/charC.png", (int)EDGE_MARGIN, (int)EDGE_MARGIN, (int)LABEL_H, (int)LABEL_W);
}

/**
 * Displays new credits' number on the label
 */
void Label::newNumber() {
	if (DEBUG)
		printf("[LABEL] credits = %i\n", credits);
	auto str = std::to_string(credits);
	int key = 1;
	for (char const &c : str) {
		std::string filename = ASSETS_FOLDER + "char" + c + ASSET_EXTENSION;
		label[key] = new GameObject(&filename[0], (int)(EDGE_MARGIN + LABEL_W * key + LOGO_MARGIN), (int)EDGE_MARGIN, (int)LABEL_H, (int)LABEL_W);
		key++;
	}
}

/**
 * Updates Label
 */
void Label::update() {
	if (Game::getCredits() != credits) {
		credits = Game::getCredits();

		clean();
		addLogo();
		newNumber();
	}
}

/**
 * Renders Label
 */
void Label::render() {
	for (auto tuple = label.begin(); tuple != label.end(); tuple++)
		tuple->second->render();
}

/**
 * Cleans Label
 */
void Label::clean() {
	for (auto tuple = label.begin(); tuple != label.end(); tuple++)
		tuple->second->clean();

	label.clear();
}