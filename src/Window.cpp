#include "Window.hpp"
#include <thread>
#include <chrono>

Window::Window(int width, int height):
			window(SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)),
			renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)),
			IsGameUp(true)
	{
		if(SDL_Init(SDL_INIT_VIDEO) != 0){
			throw std::runtime_error("Couldn't init SDL");
		}
	}

void Window::ClearWindow(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

void Window::DrawObjects(){
	ClearWindow();
	for(auto& object : enemies){
		object->Update(renderer);
	}
	SDL_RenderPresent(renderer);
}

void Window::PushObject(const std::shared_ptr<Entity>& o){
	enemies.push_back(o);
}

void Window::Update(int delay){
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		ClearWindow();
		DrawObjects();
		SDL_RenderPresent(renderer);
}

static Entity::MOVE_DIRECTION ChooseEntityDirection(const EventHandler& event_handler){
	if ( event_handler.IsButtonPressed(EventHandler::BUTTON::A)){
		return Entity::MOVE_DIRECTION::LEFT;
	}
	if ( event_handler.IsButtonPressed(EventHandler::BUTTON::D)){
		return Entity::MOVE_DIRECTION::RIGHT;
	}
	return Entity::MOVE_DIRECTION::NONE;
}

void Window::MainLoop(){
	static SDL_Event e;
	while(IsGameUp){
		while(SDL_PollEvent(&e)){
			IsGameUp = !event_handler.IsGameClosed(e);
			event_handler.UpdateKeys(e);
			auto dir = ChooseEntityDirection(event_handler);
			enemies.at(0)->Move(dir);
		}
		Update(10);
	}
}

Window::~Window(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = nullptr;
	window = nullptr;
}
