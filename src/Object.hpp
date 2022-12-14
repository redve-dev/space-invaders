#pragma once
#include <SDL2/SDL.h>
#include <glm/vec2.hpp>
#include <iostream>
#include <string>
#include "Logger.hpp"

class Object{
	glm::vec2 position;
	glm::vec2 size;
	public:
	Object(const glm::vec2& pos, const glm::vec2& size);
	void Draw(SDL_Renderer* renderer) const;
	void Move(const glm::vec2& vec);
	void SetPosition(const glm::vec2& pos);
	void SetSize(const glm::vec2& size);
	void Print(const std::string& prefix = "") const;
	friend class Logger;
	bool IsPointInside(const glm::vec2& point);
};

std::ostream& operator<<(std::ostream& out, const glm::vec2& vec);
