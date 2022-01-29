//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#ifndef CINPUTHANDLER_HPP
#define CINPUTHANDLER_HPP

#include <vector>
#include <SDL.h>
#include "CKey.hpp"

namespace MiniCraft {
//	class CKey;

	class CInputHandler {
	public:
		std::vector<CKey> keys = std::vector<CKey>();
		CKey up;
		CKey down;
		CKey left;
		CKey right;
		CKey attack;
		CKey menu;
	public:
		CInputHandler();
		void releaseAll();
		void tick();
		void toggle( SDL_Event *evt, bool pressed );

		void printState();
	};
}

#endif
