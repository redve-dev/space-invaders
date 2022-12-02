#include "Enemy.hpp"

Enemy::Enemy(const glm::i16vec2& position):
	Hitbox(glm::vec2(position.x * 50, position.y * 50), glm::vec2(50,50)),
	IsAlive(true),
	position(position)
{}

void Enemy::Move(Enemy::MOVE_DIRECTION dir){
	switch(dir){
		case Enemy::MOVE_DIRECTION::LEFT:
			position += glm::vec2(-1, 0);
			break;
		case Enemy::MOVE_DIRECTION::RIGHT:
			position += glm::vec2(1, 0);
			break;
		case Enemy::MOVE_DIRECTION::DOWN:
			position += glm::vec2(0, -1);
			break;
	}
}

void Enemy::Update(){
	//static int move_direction = 1;
	if(IsAlive){

	}
}

void Enemy::ReactToBullet(const glm::vec2& bullet_coordinates){
	if (Hitbox.IsPointInside(bullet_coordinates)){
		IsAlive = false;
	}
}
