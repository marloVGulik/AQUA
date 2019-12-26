#include "AQUA.h"

void pollEvents(Window& window, Rect& rect) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		rect.pollEvents(event);
		window.pollEvents(event);
	}
}

int main(int argc, char* argv[]) {
	Window window("OwO", 800, 600);
	Rect rect(420, 420, 69, 100, "data/textures/yah.png");

	while (!window.isClosed()) {
		pollEvents(window, rect);
		rect.draw();
		window.clear();
	}

	return 0;
}