#pragma once
#include "Object.hpp"

class Entity{
	public:
		enum class MOVE_DIRECTION{
			LEFT,
			RIGHT,
			DOWN,
			UP,
			NONE
		};
	
	protected:
	float hitbox_side_length;
	Object hitbox;
	bool IsAlive;
	glm::vec2 position;
	void SetPosition(const glm::vec2& pos);
	public:
	void Move(MOVE_DIRECTION dir);
	Entity(const glm::vec2 & position, float hitbox_side=50);
	void Update(SDL_Renderer* renderer);
};
