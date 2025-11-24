#pragma once
#include <memory>
#include <vector>
#include "GlobalStructs.hpp"
#include "Euphoria/Systems/System.hpp"

namespace Euphoria::LayerStack {
	class Layer;

	class Stack : public Systems::System {
	public:
		Stack();
		~Stack();

		template <typename T, typename... Args>
		std::shared_ptr<T> PushAndCreateLayer(Args&&... args) {
			static_assert(std::is_base_of<Layer, T>::value, "T must derive from Layer");

			auto layer = std::make_shared<T>(std::forward<Args>(args)...);
			PushLayer(layer);

			//EUPHORIA_LOG("Pushed and created layer of type %s", typeid(layer).name());
			return layer;
		}

		void PushLayer(std::shared_ptr<Layer> layer);
		void PopLayer(std::shared_ptr<Layer> layer);
		void PollEvent(Euphoria::Global::StackEvent ev);

		template<typename T>
		std::shared_ptr<Layer> FindLayer(T layer) {
			for (auto& layer : m_Layers) {
				if (auto casted = std::dynamic_pointer_cast<T>(layer)) {
					return casted;
				}
			}
			return nullptr;
		}

	protected:
		std::vector<std::shared_ptr<Layer>> m_Layers;
	};
}