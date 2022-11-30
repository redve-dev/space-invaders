#include "SDL_video.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <memory>
#include <exception>
#include <chrono>
#include <thread>

class Object{
	double x, y;
	int w, h;
	public:
	Object(double posx, double posy, int width, int height):
		x(posx),
		y(posy),
		w(width),
		h(height){}

	void Draw(SDL_Renderer* renderer){
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_Rect dummy{
				.x=static_cast<int>(x),
				.y=static_cast<int>(y),
				.w=w,
				.h=h
		};
		SDL_RenderDrawRect(renderer, &dummy);
	}

	void move(double x, double y){
		this->x += x;
		this->y += y;
	}

	void print(){
		std::cout<<x<<' '<<y<<'\n';
	}
};

class Window{
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		std::vector<std::shared_ptr<Object>> objects;
		bool IsGameUp;

		void ClearWindow(){
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderClear(renderer);
		}

		void DrawObjects(){
			ClearWindow();
			for(auto& object : objects){
				object->Draw(renderer);
			}
			SDL_RenderPresent(renderer);
		}
	public:
		Window(int width, int height):
			window(SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)),
			renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)),
			IsGameUp(true)
	{
		if(SDL_Init(SDL_INIT_VIDEO) != 0){
			throw std::runtime_error("Couldn't init SDL");
		}
	}

		~Window(){
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			renderer = nullptr;
			window = nullptr;
		}

		void PushObject(const std::shared_ptr<Object>& o){
			objects.push_back(o);
		}

		void Update(int delay){
			if(IsGameUp){
				std::this_thread::sleep_for(std::chrono::milliseconds(delay));
				ClearWindow();
				DrawObjects();
				SDL_RenderPresent(renderer);
			}
		}

		void MainLoop(){
			SDL_Event e;
			while(IsGameUp){
				objects[0]->move(0.1, 0.1);
				//objects[0]->print();
				while(SDL_PollEvent(&e)){
					if(e.type == SDL_QUIT){
						IsGameUp=false;
					}
				}
				Update(10);
			}
		}
};

int main(){
	auto o = std::make_shared<Object>(400, 300, 50, 50);
	auto g = Window(800, 600);
	g.PushObject(o);
	g.MainLoop();

}
