#include "button.h"

/**
 * Button constructor
 * @param filename Texture filename
 * @param renderer Target renderer
 * @param xPosition Position in the X axis
 * @param yPosition Position in the Y axis
 * @param rectH Rectangle height
 * @param rectW Rectangle width
 * @param buttonID Button identifier
 */
Button::Button(const char* filename, int xPosition, int yPosition, int rectH, int rectW, int buttonID)
	: GameObject{ filename, xPosition, yPosition, rectH, rectW } {
	
}

/**
 * Updates button status
 */
void Button::update() {

}

/**
 * Triggers the button's action 
 */
void Button::action() {

}