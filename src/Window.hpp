#pragma once
#include "Object.hpp"
#include "Entity.hpp"
#include "EventHandler.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include "Player.hpp"
class Window{
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		EventHandler event_handler;

		std::vector<std::shared_ptr<Entity>> enemies;
		std::shared_ptr<Player> player;
		bool IsGameUp;
		void ClearWindow();
		void DrawObjects();
	public:
		Window(int width, int height);
		~Window();
		void PushObject(const std::shared_ptr<Entity>& o);
		void Update(int delay);
		void MainLoop();
};
