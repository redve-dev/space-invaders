#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Logger.hpp"

class EventHandler{
	std::vector<bool> buttons_state;
	public:
	enum class BUTTON{
		A,
		D,
		SPACE,

		LENGTH
	};
	EventHandler();
	void UpdateKeys(const SDL_Event& e);
	bool IsButtonPressed(BUTTON b) const;
	bool IsGameClosed(const SDL_Event& e) const;
	friend class Logger;
};
