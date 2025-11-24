#include "EditorLayer.hpp"
#include "ImGui/imgui.h"

using namespace EuphoriaEditor;
using namespace Core;

using namespace Euphoria;
using namespace LayerStack;
using namespace Global;

EditorLayer::EditorLayer() {}
EditorLayer::~EditorLayer() {}

void EditorLayer::OnAttach() {
	EUPHORIA_LOG("Successfully initialized the editor layer");
}

void EditorLayer::OnDeattach() {

}

void EditorLayer::OnEvent(StackEvent eventCode) {
	if (eventCode == StackEvent::GuiRender) {
		ImGui::Begin("Editor Debug");
		ImGui::End();
	}
}