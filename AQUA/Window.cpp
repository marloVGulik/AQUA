#include "Window.h"

SDL_Renderer* Window::renderer = nullptr;

Window::Window(const std::string& title, int width, int height) : 
	_title(title), _width(width), _height(height)
{
	_closed = !init();
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}

bool Window::init() {
	std::cout << "Initializing SDL2... ";
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL!\n";
		return false;
	}
	std::cout << "Done!\n";

	std::cout << "Initializing SDL2_image... ";
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << "\n";
		return false;
	}
	std::cout << "Done!\n";

	std::cout << "Creating window... ";
	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height, 0
	);

	if (_window == nullptr) {
		std::cerr << "Failed to create a window!\n";
		return false;
	}
	std::cout << "Done!\n";

	std::cout << "Creating renderer... ";
	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		std::cerr << "Failed to create renderer!\n";
		return false;
	}
	std::cout << "Done!\n";

	return true;
}

void Window::pollEvents(SDL_Event &event) {
	switch (event.type)
	{
	case SDL_QUIT:
		_closed = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			std::cout << "Exiting program\n";
			_closed = true;
			break;
		default:
			break;
		}
		break;
	case SDL_MOUSEMOTION: // Mouse motion detection
		std::cout << event.motion.x << ", " << event.motion.y << "\n";
		break;
	case SDL_MOUSEBUTTONDOWN: // Mouse click detection (any button :()
		std::cout << "Mouse clicked!\n";
		break;
	case SDL_MOUSEBUTTONUP: // Mouse unclick detection OwO
		std::cout << "Mouse unlclicked?\n";
		break;
	default:
		break;
	}
}

void Window::clear() const {
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
}