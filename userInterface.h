#ifndef userInterface_h
#define userInterface_h

#ifdef __linux__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include <stdio.h>
#include <iostream>

#include "button.h"
#include "label.h"

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
	void clean();
private:
	int mouseLock;
	Button * creditsInButton;
	Button * creditsOutButton;
	Button * startButton;
	Label * creditsLabel;
};

#endif