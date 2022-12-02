#include "Object.hpp"
#include <cstdio>
#include <functional>
#include <sstream>

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
	SDL_RenderFillRect(renderer, &dummy);
}

void Object::Move(const glm::vec2& vec){
	position += vec;
}

void Object::SetPosition(const glm::vec2& pos){
	position = pos;
}

static std::string CreateFormattedMessage(const char* prefix, const glm::vec2& vec){
	std::stringstream ss;
	ss<<prefix<<'{'<<vec<<"}\n";
	return ss.str();
}

void Object::Print(const std::string& prefix) const {
	const std::string pos_info = CreateFormattedMessage("Position:\n\t", position);
	const std::string size_info = CreateFormattedMessage("Size:\n\t", size);
	const std::string result_info = prefix+'\n'+pos_info + size_info+'\n';
	Logger::LogMessage(Logger::LogLevel::DEBUG, result_info.c_str());
}

std::ostream& operator<<(std::ostream& out, const glm::vec2& vec){
	out<<"x: "<<vec.x<<", y: "<<vec.y;
	return out;
}

bool Object::IsPointInside(const glm::vec2& point){
	return point.x >= position.x && point.x <= position.x+size.x &&
		point.y >= position.y && point.y <= position.y+size.y;

}

void Object::SetSize(const glm::vec2& size){
	this->size = size;
}
