#include "Object.hpp"
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
	SDL_RenderDrawRect(renderer, &dummy);
}

void Object::Move(const glm::vec2& vec){
	position += vec;
}

std::ostream& operator<<(std::ostream& out, const glm::vec2& vec){
	out<<"x: "<<vec.x<<", y: "<<vec.y;
	return out;
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
