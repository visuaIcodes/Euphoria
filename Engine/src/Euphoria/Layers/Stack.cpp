#include "Stack.hpp"
#include "Layer.hpp"
#include <iostream>
#include <typeinfo>

using namespace Euphoria;
using namespace LayerStack;

Stack::Stack() {}
Stack::~Stack() {}

void Stack::PushLayer(std::shared_ptr<Layer> layer) {
	EUPHORIA_LOG("Pushed layer of type %s", typeid(layer).name());

	layer->OnAttach();
	m_Layers.push_back(layer);
}

void Stack::PopLayer(std::shared_ptr<Layer> layer) {
	if (layer == nullptr)
		return;
	
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

void Stack::Shutdown() {
	for (auto& layer : m_Layers) {
		PopLayer(layer); // Pop all the layers
		layer.reset();
	}
}