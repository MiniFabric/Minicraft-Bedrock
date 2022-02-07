//
// Created by ENDERZOMBI102 on 29/01/2022.
//
#ifndef CKEY_HPP
#define CKEY_HPP

#include <vector>
#include <set>
#include "raylib.h"

namespace MiniCraft::Input {
	class CInputHandler;

	class CKey {
	private:
		CInputHandler *handler = nullptr;
		std::vector<KeyboardKey> boundKeys{};
	public:
		int presses = 0, absorbs = 0;
		bool down = false, clicked = false;
	public:
		CKey() = default;
		~CKey();

		auto toggle(bool pressed) -> void;
		auto tick() -> void;
		auto setInputHandler( CInputHandler *pHandler ) -> void;

		auto operator==(const CKey &other) const -> bool;
		auto operator!=(const CKey &other) const -> bool;

		auto getBoundKeys() -> std::vector<KeyboardKey>;
		auto addBoundKey( std::initializer_list<KeyboardKey> keys ) -> void;

		void handle(KeyboardKey key);
	};
}
#endif
