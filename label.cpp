#include "label.h"

/**
 * Label constructor
 */
Label::Label() {
	this->credits = 0;

	//credits logo
	label[0] = new GameObject("assets/charC.png", (int)EDGE_MARGIN, (int)EDGE_MARGIN, (int)LABEL_H, (int)LABEL_W);

	//credits number
	label[1] = new GameObject("assets/char0.png", (int)(EDGE_MARGIN + LABEL_W + LOGO_MARGIN), (int)EDGE_MARGIN, (int)LABEL_H, (int)LABEL_W);
}

/**
 * Updates Label
 */
void Label::update() {

}

/**
 * Renders Label
 */
void Label::render() {
	for (auto gmObj = label.begin(); gmObj != label.end(); gmObj++) {
		gmObj->second->render();
	}
}