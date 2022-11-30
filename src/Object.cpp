#include "Object.hpp"

Object::Object(const glm::vec2& pos, const glm::vec2& size):
	position(pos),
	size(size)
{}

void Object::Draw(SDL_Renderer* renderer){
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_Rect dummy{
			.x=static_cast<int>(position.x),
			.y=static_cast<int>(position.y),
			.w=static_cast<int>(size.x),
			.h=static_cast<int>(size.y) 
	};
	SDL_RenderDrawRect(renderer, &dummy);
}

void Object::Move(const glm::vec2& vec){
	position += vec;
}
