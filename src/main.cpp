#include "Object.hpp"
#include "Window.hpp"

int main(){
	Logger::SetLogLevel(Logger::LogLevel::DEBUG);
	auto o = std::make_shared<Entity>(glm::vec2(400, 300), 50);
	auto g = Window(800, 600);
	auto p = g.CreatePlayer(glm::vec2(200,200));
	g.PushObject(o);
	g.MainLoop();
}
