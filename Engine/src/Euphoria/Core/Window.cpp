#include "Euphoria/Rendering/Renderer.hpp"
#include "Window.hpp"
#include <chrono>
#include <thread>

using namespace Euphoria;
using namespace Core;
using namespace Rendering;

Window::Window(Global::WindowCreationData& params, Global::EuphoriaRuntimeInfo runtimeInfo) 
	: m_Width(params.WindowWidth), m_Height(params.WindowHeight), m_Title(params.WindowTitle), m_RuntimeInfo(runtimeInfo) {
	CreateWindow();
}

Window::~Window() {}

bool Window::IsRunning() {
	return m_RenderWindow->isOpen();
}

std::optional<sf::Event> Window::PollEvent() {
	return m_RenderWindow->pollEvent();
}

void Window::CreateWindow() {
	EUPHORIA_LOG("Creating Window");

	std::string title = std::string(m_Title) + " - " + 
		EUPHORIA_ARCH_STRING + " " +
		EUPHORIA_CONFIGURATION_STRING;

	if (m_RuntimeInfo.HeadlessMode) title += " [Headless]";

#ifdef _DEBUG
	title += " [" + std::string(__DATE__) + " " + __TIME__ + "]";
#endif

	EUPHORIA_LOG("Creating RenderWindow with Title: %s", title.c_str());
	m_RenderWindow = new sf::RenderWindow(sf::VideoMode(sf::Vector2u(m_Width, m_Height)), title.c_str());
}

void Window::CreateRenderer(Global::RendererCreationData params) {
	EUPHORIA_LOG("Creating Renderer");
	m_Renderer = new Rendering::Renderer(m_RenderWindow, params);
}

void Window::SetVSync(bool vsync) {
	m_RenderWindow->setVerticalSyncEnabled(vsync);
}

void Window::SetFramerateLimit(int limit) {
	m_RenderWindow->setFramerateLimit(limit);
}