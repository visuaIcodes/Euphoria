#pragma once
#include <memory>
#include <vector>
#include "GlobalStructs.hpp"

namespace Euphoria::LayerStack {
	class Layer;

	class Stack {
	public:
		Stack();
		~Stack();

		template <typename T, typename... Args>
		std::shared_ptr<T> PushAndCreateLayer(Args&&... args);

		void PushLayer(std::shared_ptr<Layer> layer);
		void PopLayer(std::shared_ptr<Layer> layer);

		void PollEvent(Euphoria::Global::StackEvent ev);

		template<typename T>
		std::shared_ptr<Layer> FindLayer(T layer);

	protected:
		std::vector<std::shared_ptr<Layer>> m_Layers;
	};
}