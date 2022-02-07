//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#ifndef CINPUTHANDLER_HPP
#define CINPUTHANDLER_HPP

#include <vector>
#include "CKey.hpp"
#include "raylib-cpp.hpp"

namespace MiniCraft::Input {
//	class CKey;

	class CInputHandler {
	public:
		std::vector<CKey*> bindings{};
		CKey up;
		CKey down;
		CKey left;
		CKey right;
		CKey attack;
		CKey menu;
	public:
		CInputHandler();

		auto releaseAll() -> void;
		auto tick() -> void;

		auto printState() const -> void;
	};
}

#endif
