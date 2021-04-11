#ifndef userInterface_h
#define userInterface_h

#include "SDL.h"
#include "button.h"
#include "label.h"

#include <stdio.h>
#include <iostream>

/**
 * @class UserInterface
 * @brief UserInterface class that encompases all UI elements
 */
class UserInterface {
public:
	UserInterface();
	~UserInterface() {};

	void update();
	void render();
private:
	int buttonLock;
	Button * creditsInButton;
	Button * creditsOutButton;
	Button * startButton;
	Label * creditsLabel;
};

#endif