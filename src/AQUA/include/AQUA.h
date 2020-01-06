#pragma once

namespace Aqua {
	class EXPORT Window
	{
	public:
		Window(const std::string& title, int width, int height);
		~Window();

	private:
		std::string _title;
		int _width = 800;
		int _height = 600;

		bool _closed = false;

		SDL_Window* _window = nullptr;
	};
}