#pragma once
#include "GlobalStructs.hpp"

namespace Euphoria::LayerStack {
	class Layer {
	public:
		virtual ~Layer() {};
		virtual void OnAttach() {}
		virtual void OnDeattach() {}
		virtual void OnEvent(Global::StackEvent eventCode) {}
	};
}