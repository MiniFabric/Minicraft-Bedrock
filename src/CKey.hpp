//
// Created by ENDERZOMBI102 on 29/01/2022.
//
#ifndef CKEY_HPP
#define CKEY_HPP

#include "InputHandler.hpp"

namespace MiniCraft {
	class CKey {
	private:
		CInputHandler *handler;

	public:
		int presses = 0, absorbs = 0;
		bool down = false, clicked = false;
	public:
		explicit CKey(CInputHandler *pHandler) noexcept;

		~CKey();

		void toggle(bool pressed);

		void tick();

		bool operator==(const CKey &other) const;

		bool operator!=(const CKey &other) const;
	};
}
#endif
