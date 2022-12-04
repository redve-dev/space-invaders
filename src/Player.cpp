#include "Player.hpp"
#include "src/Entity.hpp"

Player::Player(const glm::vec2 &pos):
	Entity(pos)
{

}

void Player::Shoot(){
	Logger::LogMessage(Logger::LogLevel::DEBUG, "Shot");
}
