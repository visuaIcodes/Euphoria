#pragma once
#include "Euphoria/Layers/Layer.hpp"

namespace EuphoriaEditor::Core {
	class EditorLayer : public Euphoria::LayerStack::Layer {
	public:
		EditorLayer();
		~EditorLayer();

		void OnAttach() override;
		void OnDeattach() override;
		void OnEvent(Euphoria::Global::StackEvent eventCode) override;
	};
}