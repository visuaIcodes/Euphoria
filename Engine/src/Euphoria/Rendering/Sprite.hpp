#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

namespace Euphoria::Rendering {
	class Sprite {
	public:
		Sprite(std::shared_ptr<sf::Sprite> sprite, std::shared_ptr<sf::Texture> texture);
		~Sprite();

		static std::shared_ptr<Euphoria::Rendering::Sprite> CreateSprite(const std::string& path, const sf::IntRect& rect, const sf::Vector2f& pos);
		const sf::Drawable& GetDrawable() const;

		void ApplyTransformations(sf::Vector2f position, sf::Vector2f size, sf::Angle rotationAngle);

	private:
		std::shared_ptr<sf::Sprite> m_Sprite;
		std::shared_ptr<sf::Texture> m_Texture;
	};
}