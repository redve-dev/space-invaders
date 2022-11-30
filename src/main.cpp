#include "Object.hpp"
#include "Window.hpp"

int main(){
	auto o = std::make_shared<Object>(glm::vec2(400, 300), glm::vec2(50, 50));
	auto g = Window(800, 600);
	g.PushObject(o);
	g.MainLoop();
}
