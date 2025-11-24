#pragma once
#include "Euphoria/Layers/Layer.hpp"

namespace Euphoria::Layers {
	class EngineRenderingLayer : public LayerStack::Layer {
	public:
		EngineRenderingLayer();
		~EngineRenderingLayer();

		void OnAttach() override;
		void OnDeattach() override;
		void OnEvent(Euphoria::Global::StackEvent eventCode) override;

	private:
		void Update();
	};
}