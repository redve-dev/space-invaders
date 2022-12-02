#include "Enemy.hpp"

Enemy::Enemy(const glm::i16vec2& pos):
Entity(glm::vec2(0, 0)){
	SetPosition(pos);

}

void Enemy::ReactToBullet(const glm::vec2& bullet_coordinates){
	if (hitbox.IsPointInside(bullet_coordinates)){
		IsAlive = false;
	}
}
