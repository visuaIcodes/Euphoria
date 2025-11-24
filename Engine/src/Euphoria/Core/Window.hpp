#pragma once
#include "GlobalStructs.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Euphoria/Rendering/Renderer.hpp"

namespace Euphoria::Core {
	class Window {
	public:
		Window(Global::WindowCreationData& params, Global::EuphoriaRuntimeInfo runtimeInfo);
		~Window();

		bool IsRunning();
		std::optional<sf::Event> PollEvent();

		void SetVSync(bool vsync);
		void SetFramerateLimit(int limit);

		void CreateRenderer(Global::RendererCreationData params);

	private:
		void CreateWindow();

	private:
		int m_Width, m_Height;
		const char* m_Title;

		Global::EuphoriaRuntimeInfo m_RuntimeInfo;

		sf::RenderWindow* m_RenderWindow;
	};
}