//
// Created by ENDERZOMBI102 on 11/02/2022.
//

#include "InputHandler.hpp"
#include "CKey.hpp"


namespace Minicraft::Core::IO {

	auto InputHandler::addKeyTyped( std::string *typing, std::string *pattern ) -> std::string* {
		return {};
	}

	auto InputHandler::getPhysKey( std::string *keyText ) -> CKey* {
		return {};
	}

	auto InputHandler::toggle( KeyboardKey keyCode, bool pressed ) -> void {

	}

	auto InputHandler::resetKeyMap() -> void {

	}

	auto InputHandler::tick() -> void {

	}

	auto InputHandler::releaseAll() -> void {

	}

	auto InputHandler::setKey() -> void {

	}

	auto InputHandler::getMapping() -> void {

	}

	auto InputHandler::getKey( std::string *keyText, bool getFromMap ) -> CKey* {

	}

	auto InputHandler::getAllPressedKeys() -> std::vector<CKey *>* {
		return {};
	}

	auto InputHandler::getCurrentModifiers() -> std::string* {

	}

	auto InputHandler::getKeyPreference() -> std::string* {

	}

	auto InputHandler::changeKeyBinding( std::string *actionKey ) -> void {

	}

	auto InputHandler::addKeyBinding( std::string *actionKey ) -> void {

	}

	auto InputHandler::keyPressed() -> void {

	}

	auto InputHandler::keyReleased() -> void {

	}

	auto InputHandler::keyTyped() -> void {

	}
}