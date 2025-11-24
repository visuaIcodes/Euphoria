#pragma once
#include "Euphoria/Layers/Layer.hpp"

namespace Euphoria::Layers {
	class EngineLayer : public LayerStack::Layer {
	public:
		EngineLayer();
		~EngineLayer();

		void OnAttach() override;
		void OnDeattach() override;
		void OnEvent(Euphoria::Global::StackEvent eventCode) override;

	private:
		void Update();
	};
}