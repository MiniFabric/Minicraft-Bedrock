//
// Created by ENDERZOMBI102 on 28/01/2022.
//
#pragma once

#include "memory"
#include "Const.hpp"
#include "input/InputHandler.hpp"
#include "raylib-cpp.hpp"

namespace MiniCraft {
	class CApp {
		bool running;
		std::unique_ptr<raylib::Window> window;
		Input::CInputHandler inputHandler;
	public:
		CApp() noexcept;

		auto run() -> int;

		auto init() -> void;

		auto tick() -> void;
		auto render() -> void;
		auto cleanup() -> void;
		auto resetGame() -> void;
	};

	static CApp *GAME = new CApp(); // NOLINT(cert-err58-cpp)
}

