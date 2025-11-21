#pragma once
#include "ImGui/imgui.h"
#include "SFML/Graphics.hpp"

namespace Euphoria::Rendering {
	class Gui {
	public:
		static bool InitializeContext(sf::RenderWindow& window);
		static void ShutdownContext();

		static void ProcessEvent(sf::RenderWindow& window, sf::Event& event);

		static void BeginRender(sf::RenderWindow& window);
		static void RenderContent();
		static void EndRender(sf::RenderWindow& window);

	private:
		static ImGuiContext* m_ImGuiContext;
	};
}