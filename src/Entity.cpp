#include "Entity.hpp"

Entity::Entity(const glm::vec2& position):
	Hitbox(glm::vec2(position.x * 50, position.y * 50), glm::vec2(50,50)),
	IsAlive(true),
	position(position)
{}

void Entity::Move(Entity::MOVE_DIRECTION dir){
	switch(dir){
		case Entity::MOVE_DIRECTION::LEFT:
			position += glm::vec2(-1, 0);
			break;
		case Entity::MOVE_DIRECTION::RIGHT:
			position += glm::vec2(1, 0);
			break;
		case Entity::MOVE_DIRECTION::DOWN:
			position += glm::vec2(0, -1);
			break;
		case Entity::MOVE_DIRECTION::UP:
			position += glm::vec2(0, -1);
			break;
	}
}

void Entity::Update(){
	//static int move_direction = 1;
	if(IsAlive){

	}
}
