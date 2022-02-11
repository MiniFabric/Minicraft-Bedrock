//
// Created by ENDERZOMBI102 on 11/02/2022.
//

#pragma once


#include <string>
#include <vector>
#include "raylib.h"


namespace  Minicraft::Core::IO {
	class CKey;

	class InputHandler {
		std::string lastKeyTyped;
		std::string keyTypedBuffer;
	private:
		virtual auto initKeyMap() -> void = 0;

		virtual auto getPhysKey( std::string *keyText ) -> CKey*;

		virtual auto toggle( KeyboardKey keyCode, bool pressed ) -> void;

		virtual auto getKey( std::string *keyText, bool getFromMap ) -> CKey*;


		static auto isMod( const std::string *keyName ) -> bool {
			return (
					keyName->contains("CTRL") ||
					keyName->contains("SHIFT") ||
					keyName->contains("ALT")
			);
		};
		static auto isMod( KeyboardKey key ) -> bool {
			return (
					key == KEY_LEFT_SHIFT ||
					key == KEY_RIGHT_SHIFT ||
					key == KEY_LEFT_CONTROL ||
					key == KEY_RIGHT_CONTROL ||
					key == KEY_LEFT_ALT ||
					key == KEY_RIGHT_ALT
			);
		};

	public:
		virtual auto resetKeyMap() -> void;

		virtual auto tick() -> void;

		virtual auto releaseAll() -> void;

		virtual auto setKey() -> void;

		virtual auto getMapping() -> void;

		virtual auto getKey( std::string *keyText ) -> CKey* { return getKey( keyText, true ); };

		virtual auto getAllPressedKeys() -> std::vector<CKey*>*;

		virtual auto getCurrentModifiers() -> std::string*;

		virtual auto getKeyPreference() -> std::string*;

		virtual auto changeKeyBinding( std::string *actionKey ) -> void;

		virtual auto addKeyBinding( std::string *actionKey ) -> void;

		virtual auto keyPressed() -> void;

		virtual auto keyReleased() -> void;

		virtual auto keyTyped() -> void;

		virtual auto addKeyTyped( std::string *typing, std::string *pattern ) -> std::string*;

	};
}
