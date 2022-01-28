//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#pragma once

#include <vector>
#include <SDL.h>
#include "CKey.hpp"

namespace MiniCraft {
	class CInputHandler {
		friend class CKey;
	public:
		std::vector<CKey> keys = std::vector<CKey>();
		CKey up = CKey();
		CKey down = CKey();
		CKey left = CKey();
		CKey right = CKey();
		CKey attack = CKey();
		CKey menu = CKey();
	public:
		CInputHandler() = default;
		void releaseAll();
		void tick();
		void toggle( SDL_Event *evt, bool pressed );

		void printState();
	};
}
