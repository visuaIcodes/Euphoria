#include "Euphoria/Input/InputSystem.hpp"

using namespace Euphoria;
using namespace Input;

InputSystem::InputSystem() {}
InputSystem::~InputSystem() {}

bool InputSystem::IsKeyPressed(KeyCode key) {
	return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
}

bool InputSystem::IsMouseButtonPressed(MouseButton button) {
	return sf::Mouse::isButtonPressed((sf::Mouse::Button)button);
}

sf::Vector2i InputSystem::GetMousePosition() {
	return sf::Mouse::getPosition();
}