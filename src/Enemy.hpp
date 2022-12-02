#include "Object.hpp"

class Enemy{
	public:
		enum class MOVE_DIRECTION{
			LEFT,
			RIGHT,
			DOWN
		};
	Object Hitbox;
	bool IsAlive;
	glm::i16vec2 position;
	void Move(MOVE_DIRECTION dir);
	public:
	Enemy(const glm::i16vec2 & position);
	void Update();
	void ReactToBullet(const glm::vec2& bullet_coordinates);
};
