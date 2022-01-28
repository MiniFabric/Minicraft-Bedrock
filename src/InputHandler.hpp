//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#pragma once

#include <vector>

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
	};

	static std::vector<CKey> *keys;
	static CKey up;
	static CKey down;
	static CKey left;
	static CKey right;
	static CKey attack;
	static CKey menu;

}
