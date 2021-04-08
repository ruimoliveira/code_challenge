#include "game.h"

#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[]) {
	Game game;

	try {
		game.run();
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}