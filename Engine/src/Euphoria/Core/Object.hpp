#pragma once

#include "SFML/Graphics.hpp"
#include "Euphoria/Rendering/Sprite.hpp"
#include "Euphoria/Layers/Layer.hpp"

namespace Euphoria::Core {
	class Object : public LayerStack::Layer {
	private:
		std::string Name;
		sf::Vector2f Position;
		sf::Vector2f Size;
		sf::Angle Rotation;
		std::shared_ptr<Rendering::Sprite> Sprite;

	public:
		Object(std::string name); // avoid creating objects without going through a system
		~Object();

	public:
		void OnAttach() override;
		void OnDeattach() override;
		void OnEvent(Global::StackEvent eventCode) override;

		// Creates a object under the active scene
		static std::shared_ptr<Object> CreateObject(std::string name);
		//static std::shared_ptr<Object> CreateObjectAtTargetScene(std::string name, Scene* scene); impl later

		void SetPosition(sf::Vector2f position) noexcept {
			Position = position;
		}

		void SetSize(sf::Vector2f size) noexcept {
			Size = size;
		}

		void SetRotation(sf::Angle angle) noexcept {
			Rotation = angle;
		}

		void SetName(std::string name) noexcept {
			Name = name;
		}

		void SetSprite(std::shared_ptr<Rendering::Sprite> sprite) {
			Sprite = sprite;
		}

		sf::Vector2f GetPosition() noexcept {
			return Position;
		}

		sf::Angle GetRotation() noexcept {
			return Rotation;
		}

		sf::Vector2f GetSize() noexcept {
			return Size;
		}

		std::string GetName() noexcept {
			return Name;
		}

		std::shared_ptr<Rendering::Sprite> GetSprite() noexcept {
			return Sprite;
		}
	};
}