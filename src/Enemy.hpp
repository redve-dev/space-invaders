#include "Entity.hpp"

class Enemy: public Entity{
	public:
	void ReactToBullet(const glm::vec2& bullet_coordinates);
};
