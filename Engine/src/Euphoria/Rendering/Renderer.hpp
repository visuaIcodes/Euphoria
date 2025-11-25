#pragma once
#include "Euphoria/Layers/Layer.hpp"
#include "Euphoria/Systems/System.hpp"
#include <SFML/Graphics.hpp>

namespace Euphoria::Rendering {
	class Renderer : public Systems::System {
	public:
		Renderer(sf::RenderWindow* window, Global::RendererCreationData params);
		~Renderer();

		void Clear(sf::Color colour);

		void BeginFrame();
		void Draw(const sf::Drawable& shape);
		void PresentFrame();

		void RefreshShaders(std::string vertexShader, std::string fragmentShader);

		sf::RenderWindow* GetWindow() {
			return m_RenderWindow;
		}

		sf::Shader* GetShader() {
			return m_Shader;
		}

	protected:
		sf::Shader* m_Shader;
		sf::RenderWindow* m_RenderWindow;
		Global::ClearColourData m_BackgroundClearColour;
	};
}