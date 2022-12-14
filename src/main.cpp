#include "App.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		return 1;
	}

	mushroom::App app;
	bool success = app.run(argv);

	return !success;
}
