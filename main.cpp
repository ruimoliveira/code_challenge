#include <iostream>
#include <stdexcept>

#include "engine.h"

int main(int argc, char *argv[]) {
	Engine engine;

	try {
		engine.run();
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}