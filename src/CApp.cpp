#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
//
// Created by ENDERZOMBI102 on 28/01/2022.
//

#include <iostream>
#include <chrono>
#include "CApp.hpp"
#include "Const.hpp"

namespace MiniCraft {

	CApp::CApp() noexcept {
		this->running = true;
		this->window = std::unique_ptr<raylib::Window>();
		this->inputHandler = Input::CInputHandler();
	}

	auto CApp::run() -> int {
		std::cout << "MiniCraft Bedrock is initializing\n";

		this->init();

//		auto lastTime = std::chrono::high_resolution_clock::now();
//		double unprocessed = 0;
//		double nsPerTick = 1000000000.0 / 60;
//		long frames = 0;
//		long ticks = 0;
//		auto lastTimer1 = std::chrono::system_clock::now();

		std::cout << "MiniCraft Bedrock initialized!\n";
		while ( this->running && !this->window->ShouldClose()  ) {
			tick();
			render();
		}

		cleanup();

		return 0;
	}

	auto CApp::tick() -> void {
		this->inputHandler.tick();
	}

	auto CApp::render() -> void {
		this->window->BeginDrawing();
		{
			this->window->ClearBackground(YELLOW);
		}
		this->window->EndDrawing();
	}

	auto CApp::cleanup() -> void {
		std::cout << __FILE__ << " " << __LINE__ << std::endl;
	}

	auto CApp::init() -> void {
		this->window->Init();
		std::cout << __FILE__ << " " << __LINE__ << std::endl;
		this->window->SetSize(
				Const::WIDTH * Const::SCALE,
				Const::HEIGHT * Const::SCALE
		);
		this->window->SetTitle( "Minicraft: Bedrock Edition" );
		this->window->SetTargetFPS( 60 );
	}

	auto CApp::resetGame() -> void {

	}
}
#pragma clang diagnostic pop