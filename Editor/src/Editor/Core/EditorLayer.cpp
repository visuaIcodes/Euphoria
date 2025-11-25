#include "EditorLayer.hpp"
#include "ImGui/imgui.h"
#include "Editor/UI/InspectorLayout.hpp"
#include "Euphoria/UI/Gui.hpp"
#include "Editor/UI/EditorUI.hpp"

using namespace EuphoriaEditor;
using namespace EuphoriaEditor::UI;
using namespace Core;

using namespace Euphoria;
using namespace LayerStack;
using namespace Global;

EditorLayer::EditorLayer() {}
EditorLayer::~EditorLayer() {}

void EditorLayer::OnAttach() {
	EUPHORIA_LOG("Successfully initialized the editor layer");
	Systems::System::Get<Euphoria::LayerStack::Stack>()->PushAndCreateLayer<EditorUI>();
}

void EditorLayer::OnDeattach() {

}

void EditorLayer::OnEvent(StackEvent eventCode) {
	if (eventCode == StackEvent::GuiRender) {
		ImGui::Begin("Editor Debug");
		ImGui::End();
	}
}