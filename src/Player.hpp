#pragma once
#include "Entity.hpp"

class Player: public Entity{
	public:
		Player(const glm::vec2& pos);
		void Shoot();
};
