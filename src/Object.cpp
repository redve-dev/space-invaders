#include "Object.hpp"

Object::Object(const glm::vec2& pos, const glm::vec2& size):
	position(pos),
	size(size)
{}

void Object::Draw(SDL_Renderer* renderer) const{
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

std::ostream& operator<<(std::ostream& out, const glm::vec2& vec){
	out<<"x: "<<vec.x<<", y: "<<vec.y;
	return out;
}

static void PrintObjectField(const std::string& prefix, const glm::vec2& vec){
	std::cout<<prefix<<'{'<<vec<<"}\n";
}

void Object::Print(const std::string& prefix, const std::string& suffix) const{
	std::cout<<prefix<<'\n';
	PrintObjectField("Position:\n\t", position);
	PrintObjectField("Size:\n\t", size);
	std::cout<<suffix<<'\n';
}
