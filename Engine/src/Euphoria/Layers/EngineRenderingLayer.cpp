#include "Euphoria/Layers/EngineRenderingLayer.hpp"
#include "Euphoria/Rendering/Renderer.hpp"
#include "Euphoria/UI/Gui.hpp"
#include "Euphoria/Scene/Scene.hpp"
#include "Euphoria/Layers/Stack.hpp"

using namespace Euphoria;
using namespace Core;
using namespace Global;
using namespace Rendering;
using namespace UI;
using namespace Layers;

EngineRenderingLayer::EngineRenderingLayer() {}
EngineRenderingLayer::~EngineRenderingLayer() {}

void EngineRenderingLayer::OnAttach() {
    EUPHORIA_LOG("Successfully attached the engine rendering layer");
}

void EngineRenderingLayer::OnDeattach() {
    EUPHORIA_LOG("Successfully dettached the engine rendering layer");

}

void EngineRenderingLayer::OnEvent(StackEvent eventCode) {
    if (eventCode == StackEvent::Update) {
        this->Update();
    }
}

void EngineRenderingLayer::Update() {
    std::shared_ptr<Renderer> Renderer = Systems::System::Get<Rendering::Renderer>();
    std::shared_ptr<LayerStack::Stack> LayerStack = Systems::System::Get<LayerStack::Stack>();

    if (Renderer != nullptr) {
        Renderer->BeginFrame();
        Gui::BeginRender(*Renderer->GetWindow());
        LayerStack->PollEvent(Global::StackEvent::Render);

        if (Scene::LoadedScene != nullptr) {
            for (auto sprite : Scene::LoadedScene->GetObjects()) {
                Renderer->Draw(sprite->GetSprite()->GetDrawable());
            }
        }

        // poll the gui render event and render the gui content
        LayerStack->PollEvent(Global::StackEvent::GuiRender);
        Gui::RenderContent();

        Gui::EndRender(*Renderer->GetWindow());
        Renderer->PresentFrame();
    }
}