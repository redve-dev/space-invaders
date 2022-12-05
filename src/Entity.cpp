#include "Entity.hpp"

Entity::Entity(const glm::vec2& position, float hitbox_side):
	hitbox_side_length(hitbox_side),
	hitbox(position, glm::vec2(hitbox_side, hitbox_side)),
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
			position += glm::vec2(0, 1);
			break;
		case Entity::MOVE_DIRECTION::NONE:
			// ignore
			break;
	}
}

void Entity::SetPosition(const glm::vec2& pos){
	position = pos;
}

void Entity::Update(SDL_Renderer* renderer){
	if(IsAlive){
		hitbox.SetPosition(position);
		hitbox.SetSize(glm::vec2(hitbox_side_length, hitbox_side_length));
		hitbox.Draw(renderer);
	}
}
