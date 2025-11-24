#include "Stack.hpp"
#include "Layer.hpp"
#include <iostream>
#include <typeinfo>

using namespace Euphoria;
using namespace LayerStack;

Stack::Stack() {}
Stack::~Stack() {}

template <typename T, typename... Args>
std::shared_ptr<T> Stack::PushAndCreateLayer(Args&&... args) {
	static_assert(std::is_base_of<Layer, T>::value, "T must derive from Layer");

	auto layer = std::make_shared<T>(std::forward<Args>(args)...);
	m_Layers.push_back(layer);
	
	EUPHORIA_LOG("Pushed and created layer of type %s", typeid(layer).name());
	return layer;
}

void Stack::PushLayer(std::shared_ptr<Layer> layer) {
	EUPHORIA_LOG("Pushed layer of type %s", typeid(layer).name());

	layer->OnAttach();
	m_Layers.push_back(layer);
}

void Stack::PopLayer(std::shared_ptr<Layer> layer) {
	EUPHORIA_LOG("Popped layer of type %s", typeid(layer).name());

	layer->OnDeattach();
    for (auto it = m_Layers.begin(); it != m_Layers.end(); ++it) {
        if (it->get() == layer.get()) {
            m_Layers.erase(it);
            break;
        }
    }
}

void Stack::PollEvent(Global::StackEvent event) {
	for (auto& layer : m_Layers) {
		if (!layer || layer == nullptr)
			continue;

		layer->OnEvent(event);
	}
}

template<typename T>
std::shared_ptr<Layer> Stack::FindLayer(T layer) {
	for (auto& layer : m_Layers) {
		if (auto casted = std::dynamic_pointer_cast<T>(layer)) {
			return casted;
		}
	}
	return nullptr;
}