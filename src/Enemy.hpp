#include "Entity.hpp"

class Enemy: public Entity{
	public:
	Enemy(const glm::i16vec2& pos);
	void ReactToBullet(const glm::vec2& bullet_coordinates);
};
