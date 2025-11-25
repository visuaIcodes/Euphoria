#include "Editor/UI/EditorUI.hpp"

using namespace EuphoriaEditor;
using namespace EuphoriaEditor::UI;

EditorUI::EditorUI() {}
EditorUI::~EditorUI() {}

void EditorUI::OnAttach() {

}

void EditorUI::OnDeattach() {

}

void EditorUI::OnEvent(Euphoria::Global::StackEvent eventCode) {
	if (eventCode == Euphoria::Global::StackEvent::GuiRender) {
		inspectorLayout.Render();
	}
}