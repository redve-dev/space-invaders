#pragma once
#include "Object.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <memory>

class Window{
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		std::vector<std::shared_ptr<Object>> objects;
		bool IsGameUp;
		void ClearWindow();
		void DrawObjects();
	public:
		Window(int width, int height);
		~Window();
		void PushObject(const std::shared_ptr<Object>& o);
		void Update(int delay);
		void MainLoop();
};
