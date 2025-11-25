#pragma once
#include "ImGui/imgui.h"
#include "Euphoria/Layers/Layer.hpp"
#include "Euphoria/Layers/Stack.hpp"
#include "Editor/UI/InspectorLayout.hpp"

namespace EuphoriaEditor::UI {
	class EditorUI : public Euphoria::LayerStack::Layer {
	public:
		EditorUI();
		~EditorUI();

		void OnAttach() override;
		void OnDeattach() override;
		void OnEvent(Euphoria::Global::StackEvent eventCode) override;

	private:
		InspectorLayout inspectorLayout;
	};
}