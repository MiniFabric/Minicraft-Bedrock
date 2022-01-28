//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#pragma once

#include <vector>
#include <SDL.h>

namespace MiniCraft {
	class CKey {
	public:
		int presses = 0, absorbs = 0;
		bool down = false, clicked = false;
	public:
		CKey() noexcept;

		~CKey();

		void toggle(bool pressed);

		void tick();

		bool operator==(const CKey &other) const;
		bool operator!=(const CKey &other) const;
	};

	static std::vector<CKey> keys = std::vector<CKey>();
	static CKey up = CKey();
	static CKey down = CKey();
	static CKey left = CKey();
	static CKey right = CKey();
	static CKey attack = CKey();
	static CKey menu = CKey();


	class CInputHandler {
	public:
		CInputHandler() = default;
		void releaseAll();
		void tick();
		void toggle( SDL_Event *evt, bool pressed );

		void printState();
	};
}
