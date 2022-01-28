//
// Created by ENDERZOMBI102 on 28/01/2022.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"

#include <iostream>
#include "CApp.hpp"

CApp::CApp() {
	running = true;
	window = NULL;
}

int CApp::OnExecute() {
	if (! OnInit() ) {
		return -1;
	}

	std::cout << "MiniCraft Bedrock is initializing\n";
	std::cout << "MiniCraft Bedrock initialized!\n";

	SDL_Event Event;

	while ( running ) {
		while ( SDL_PollEvent(&Event) ) {
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

bool CApp::OnInit(){
	if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 ){
		return false;
	}

	window = SDL_CreateWindow(
			"MiniCraft Bedrock",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480,
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
	);

	if ( window == NULL ){
		return false;
	}

	return true;
}

void CApp::OnEvent( SDL_Event *Event ) {
	if ( Event->type == SDL_QUIT ) {
		running = false;
	}
}

void CApp::OnLoop() {

}

void CApp::OnRender() {

}

void CApp::OnCleanup() {

}

#pragma clang diagnostic pop