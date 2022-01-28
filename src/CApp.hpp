//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include "InputHandler.hpp"

namespace MiniCraft {
	class CApp {
		bool running;
		SDL_Window *window;
		CInputHandler inputHandler;
	public:
		CApp();

		int OnExecute();

		bool OnInit();

		void OnEvent(SDL_Event *evt);

		void OnLoop();

		void OnRender();

		void OnCleanup();
	};
}

