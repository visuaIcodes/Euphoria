#pragma once
#include "Euphoria/Systems/System.hpp"
#include "Euphoria/Input/KeyCode.hpp"
#include "Euphoria/Input/MouseButton.hpp"
#include "Euphoria/Input/MouseWheel.hpp"
#include "SFML/Graphics.hpp"

namespace Euphoria::Input {
	class InputSystem : public Systems::System {
	public:
		InputSystem();
		~InputSystem();

		bool IsKeyPressed(KeyCode key);
		bool IsMouseButtonPressed(MouseButton button);
		sf::Vector2i GetMousePosition();
		sf::Vector2i GetMousePositionRelativeToWindow(sf::RenderWindow& window);
	};
}