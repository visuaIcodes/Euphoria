#pragma once
#include "Euphoria/Layers/Layer.hpp"
#include <SFML/Graphics.hpp>

namespace Euphoria::Rendering {
	class Renderer {
	public:
		Renderer(sf::RenderWindow* window, Global::RendererCreationData params);
		~Renderer();

		void Clear(sf::Color colour);

		void BeginFrame();
		void Draw(const sf::Drawable& shape);
		void PresentFrame();

		sf::RenderWindow* GetWindow() {
			return m_RenderWindow;
		}

	protected:
		sf::RenderWindow* m_RenderWindow;
		Global::ClearColourData m_BackgroundClearColour;
	};
}