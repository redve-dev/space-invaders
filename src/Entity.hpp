#include "Object.hpp"

class Entity{
	public:
		enum class MOVE_DIRECTION{
			LEFT,
			RIGHT,
			DOWN,
			UP
		};
	
	protected:
	Object Hitbox;
	bool IsAlive;
	glm::vec2 position;
	void Move(MOVE_DIRECTION dir);
	public:
	Entity(const glm::vec2 & position);
	void Update();
};
