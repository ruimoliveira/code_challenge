#ifndef userInterface_h
#define userInterface_h

#include "SDL.h"
#include "button.h"

class UserInterface {
public:
	UserInterface(SDL_Renderer * renderer);
	~UserInterface() {};

	void update();
	void render();
private:
	Button * creditsInButton;
	Button * creditsOutButton;
	Button * startButton;
	//Label * creditsLabel;
};

#endif