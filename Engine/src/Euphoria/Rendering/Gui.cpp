#include "Euphoria/Rendering/Gui.hpp"
#include "Euphoria/Submodules/Time.hpp"
#include "ImGui/imgui-SFML.h"

using namespace Euphoria;
using namespace Rendering;

ImGuiContext* Gui::m_ImGuiContext = nullptr;

bool Gui::InitializeContext(sf::RenderWindow& window) {
	m_ImGuiContext = ImGui::CreateContext();
	if (!m_ImGuiContext) return false;

	ImGui::StyleColorsDark();

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

	return ImGui::SFML::Init(window, true);
}

void Gui::ShutdownContext() {
	ImGui::DestroyContext(m_ImGuiContext);
	ImGui::SFML::Shutdown();
}

void Gui::ProcessEvent(sf::RenderWindow& window, sf::Event& event) {
	ImGui::SFML::ProcessEvent(window, event);
}

void Gui::BeginRender(sf::RenderWindow& window) {
	static sf::Clock deltaClock;
	ImGui::SFML::Update(window, deltaClock.restart());
}

void Gui::RenderContent() {
	ImGui::Begin("Hi");
	ImGui::Text("FPS: %u", Submodules::Time::GetFramesPerSecond());
	ImGui::End();
}

void Gui::EndRender(sf::RenderWindow& window) {
	ImGui::SFML::Render(window);
}