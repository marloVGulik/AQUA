#include "Rect.h";

Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a) :
	_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{

}
Rect::Rect(int w, int h, int x, int y, const std::string &image_path) :
	_w(w), _h(h), _x(x), _y(y)
{
	auto surface = IMG_Load(image_path.c_str());

	if (!surface) {
		std::cerr << "Failed to create surface!\n";
	}
	no_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (!no_texture) {
		std::cerr << "Failed to create texture!\n";
	}
	SDL_FreeSurface(surface);
}

void Rect::draw() const {
	SDL_Rect rect = { _x, _y, _w, _h };
	if (no_texture) {
		SDL_RenderCopy(Window::renderer, no_texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}

}

void Rect::pollEvents(SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
			_x--;
			break;
		case SDLK_RIGHT:
			_x++;
			break;
		case SDLK_UP:
			_y--;
			break;
		case SDLK_DOWN:
			_y++;
			break;
		default:
			break;
		}
	}
	if (event.type == SDL_MOUSEMOTION) {
		_x += event.motion.x - _x;
		_y += event.motion.y - _y;
	}
}

Rect::~Rect() {
	SDL_DestroyTexture(no_texture);
}