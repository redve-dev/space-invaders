#include "EventHandler.hpp"
#include <iostream>
#include <exception>

EventHandler::EventHandler(){
	buttons_state.resize(static_cast<size_t>(BUTTON::LENGTH), false);
}

static void UpdatePressedKeys(SDL_Keycode key, std::vector<bool>& buttons_state, bool state){
	typedef EventHandler::BUTTON BUTTON;
	switch(key){
		case SDLK_a:
			buttons_state.at(static_cast<size_t>(BUTTON::A)) = state;
			break;
		case SDLK_d:
			buttons_state.at(static_cast<size_t>(BUTTON::D)) = state;
			break;
		case SDLK_SPACE:
			buttons_state.at(static_cast<size_t>(BUTTON::SPACE)) = state;
			break;
	}
}

void EventHandler::UpdateKeys(const SDL_Event &e){
	auto key = e.key.keysym.sym;
	if(e.type == SDL_KEYDOWN){
		UpdatePressedKeys(key, buttons_state, true);
	}
	if(e.type == SDL_KEYUP){
		UpdatePressedKeys(key, buttons_state, false);
	}
}

bool EventHandler::IsButtonPressed(BUTTON b){
	return buttons_state.at(static_cast<size_t>(b));
}

bool EventHandler::IsGameClosed(const SDL_Event &e){
	return e.type == SDL_QUIT;
}
