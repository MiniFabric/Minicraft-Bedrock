//
// Created by ENDERZOMBI102 on 28/01/2022.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"

#include <iostream>
#include <chrono>
#include "CApp.hpp"
#include "Const.hpp"

namespace MiniCraft {

	CApp::CApp() noexcept {
		this->running = true;
		this->window = NULL;
		this->inputHandler = Input::CInputHandler();
	}

	int CApp::run() {
		std::cout << "MiniCraft Bedrock is initializing\n";

		if (!initSDL() ) {
			return -1;
		}
		this->initGame();

		auto lastTime = std::chrono::high_resolution_clock::now();
		double unprocessed = 0;
		double nsPerTick = 1000000000.0 / 60;
		long frames = 0;
		long ticks = 0;
		auto lastTimer1 = std::chrono::system_clock::now();

		SDL_Event Event;

		std::cout << "MiniCraft Bedrock initialized!\n";
		while ( this->running ) {
			while ( SDL_PollEvent(&Event) ) {
				processEvent(&Event);
			}

			tick();
			render();
		}

		cleanup();

		return 0;
	}

	bool CApp::initSDL() {
		if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
			return false;
		}

		this->window = SDL_CreateWindow(
				"MiniCraft Bedrock",
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				MiniCraft::Const::WIDTH * MiniCraft::Const::SCALE,
				MiniCraft::Const::HEIGHT * MiniCraft::Const::SCALE,
				SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED
		);

		if ( this->window == NULL ) {
			return false;
		}

		return true;
	}

	void CApp::processEvent(SDL_Event *evt) {
		switch ( evt->type ) {
			case SDL_QUIT:
				this->running = false;
				break;
			case SDL_KEYDOWN:
				this->inputHandler.toggle( evt, true );
				this->inputHandler.printState();
				break;
			case SDL_KEYUP:
				this->inputHandler.toggle( evt, false );
				this->inputHandler.printState();
				break;
			default:
				break;
		}
	}

	void CApp::tick() {

	}

	void CApp::render() {

	}

	void CApp::cleanup() {

	}

	void CApp::initGame() {

	}

	void CApp::resetGame() {

	}
}

#pragma clang diagnostic pop