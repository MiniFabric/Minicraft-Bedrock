//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "input/InputHandler.hpp"
#include "raylib-cpp.hpp"

namespace MiniCraft {
	class CApp {
		bool running;
		SDL_Window *window;
		Input::CInputHandler inputHandler;
	public:
		CApp() noexcept;

		int run();

		bool initSDL();
		void initGame();

		void processEvent(SDL_Event *evt);
		void tick();
		void render();
		void cleanup();
		void resetGame();
	};

	static CApp *GAME = new CApp(); // NOLINT(cert-err58-cpp)
}

