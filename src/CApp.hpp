//
// Created by ENDERZOMBI102 on 28/01/2022.
//

#pragma once


#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

class CApp {
	bool    running;
	SDL_Window* window;
public:
	CApp();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void OnCleanup();
};


