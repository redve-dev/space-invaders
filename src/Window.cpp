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
	for(auto& object : objects){
		object->Draw(renderer);
	}
	SDL_RenderPresent(renderer);
}

void Window::PushObject(const std::shared_ptr<Object>& o){
	objects.push_back(o);
}

void Window::Update(int delay){
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		ClearWindow();
		DrawObjects();
		SDL_RenderPresent(renderer);
}

void Window::MainLoop(){
	SDL_Event e;
	while(IsGameUp){
		objects[0]->Move( glm::vec2(0.1, 0.1) );
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT){
				IsGameUp=false;
			}
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
