#include "Euphoria/Rendering/Renderer.hpp"
#include "Euphoria/Rendering/Sprite.hpp"
#include "Euphoria/UI/Gui.hpp"

using namespace Euphoria;
using namespace Rendering;

Renderer::Renderer(sf::RenderWindow* window, Global::RendererCreationData params) : m_RenderWindow(window), m_BackgroundClearColour(params.BackgroundData) {}
Renderer::~Renderer() {}

void Renderer::Clear(sf::Color colour) {
	m_RenderWindow->clear(colour);
}

void Renderer::BeginFrame() {
	sf::Color colour = sf::Color(m_BackgroundClearColour.r, m_BackgroundClearColour.g, m_BackgroundClearColour.b, m_BackgroundClearColour.a);
	Clear(colour);
}

void Renderer::Draw(const sf::Drawable& shape) {
	if (!m_RenderWindow) return;
	m_RenderWindow->draw(shape, sf::RenderStates::Default);
}

void Renderer::PresentFrame() {
	m_RenderWindow->display();
}

void Renderer::RefreshShaders(std::string vertexShader, std::string fragmentShader) {
	m_Shader = new sf::Shader();
	if (!m_Shader->loadFromFile(vertexShader, fragmentShader)) {
		EUPHORIA_ERROR("Failed to load shaders from vertex: %s, and fragment: %s", vertexShader, fragmentShader);
		return;
	}
}