#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "GlobalStructs.hpp"

namespace Euphoria::Submodules {
	class Time {
	private:
		static inline unsigned int s_Frame;
		static inline unsigned int s_FPS;
		static inline sf::Clock s_Clock;

	public:
		static inline const unsigned int GetFramesPerSecond() {
			return s_FPS;
		}

		static inline void Tick() {
			if (s_Clock.getElapsedTime().asSeconds() >= 1.f) {
				s_FPS = s_Frame;
				s_Frame = 0;
				s_Clock.restart();

				EUPHORIA_LOG("Ticked time, frames per second: %u", s_FPS);
			}

			s_Frame++;
		}
	};
}