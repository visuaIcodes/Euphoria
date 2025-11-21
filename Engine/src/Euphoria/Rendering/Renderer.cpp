#include "Euphoria/Rendering/Renderer.hpp"
#include "Euphoria/Rendering/Sprite.hpp"
#include "Euphoria/Rendering/Gui.hpp"

using namespace Euphoria;
using namespace Rendering;

Renderer::Renderer(sf::RenderWindow* window, Global::RendererCreationData params) : m_RenderWindow(window), m_BackgroundClearColour(params.BackgroundData) {}
Renderer::~Renderer() {}

void Renderer::Clear(sf::Color colour) {
	m_RenderWindow->clear(colour);
}

void Renderer::BeginFrame() {
	//EUPHORIA_LOG("Begin Frame");
	sf::Color colour = sf::Color(m_BackgroundClearColour.r, m_BackgroundClearColour.g, m_BackgroundClearColour.b, m_BackgroundClearColour.a);
	this->Clear(colour);
}

void Renderer::Draw(const sf::Drawable& shape) {
	if (!m_RenderWindow) return;
	m_RenderWindow->draw(shape, sf::RenderStates::Default);
}

void Renderer::PresentFrame() {
	m_RenderWindow->display();
}