#include "Enemy.hpp"

void Enemy::ReactToBullet(const glm::vec2& bullet_coordinates){
	if (Hitbox.IsPointInside(bullet_coordinates)){
		IsAlive = false;
	}
}
