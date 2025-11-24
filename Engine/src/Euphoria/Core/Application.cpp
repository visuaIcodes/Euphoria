#include "Euphoria/Core/Application.hpp"
#include "Euphoria/Core/Window.hpp"
#include "Euphoria/Scene/Scene.hpp"
#include "Euphoria/Rendering/Renderer.hpp"
#include "Euphoria/Rendering/Sprite.hpp"
#include "Euphoria/Rendering/Gui.hpp"
#include "Euphoria/Physics/Physics2D.hpp"
#include "Euphoria/Layers/Stack.hpp"

#include <iostream>
#include <chrono>
#include <thread>

using namespace Euphoria;
using namespace Core;
using namespace Rendering;

std::unique_ptr<Application> Application::InitializeApplication(Global::ApplicationCreationData& params) {
    return std::make_unique<Application>(params);
}

void Application::Start() {
    while (m_Window->IsRunning() || RuntimeInfo.HeadlessMode) {
        Rendering::Renderer* Renderer = m_Window->GetRenderer();
        std::shared_ptr<LayerStack::Stack> LayerStack = Systems::System::Get<LayerStack::Stack>();

        while (std::optional event = m_Window->PollEvent()) {
            sf::Event& ev = event.value();
            Rendering::Gui::ProcessEvent(*Renderer->GetWindow(), ev);
            if (event->is<sf::Event::Closed>()) {
                if (Renderer) Renderer->GetWindow()->close();
                LayerStack->PollEvent(Global::StackEvent::Quit);
                break;
            }
        }

        LayerStack->PollEvent(Global::StackEvent::Update);
        Physics::Physics2D::Simulate(1.0f / 90.0f);

        if (Renderer != nullptr) {
            Renderer->BeginFrame();
            Gui::BeginRender(*Renderer->GetWindow());
            LayerStack->PollEvent(Global::StackEvent::Render);

            if (Scene::LoadedScene != nullptr) {
                for (auto sprite : Scene::LoadedScene->GetObjects()) {
                    Renderer->Draw(sprite->GetSprite()->GetDrawable());
                }
            }

            Gui::RenderContent();
            Gui::EndRender(*Renderer->GetWindow());
            Renderer->PresentFrame();
        }
    }

    Rendering::Gui::ShutdownContext();
    Physics::Physics2D::Shutdown();
}

Application::Application(Global::ApplicationCreationData& params) : RuntimeInfo(params.RuntimeInfo) {
    EUPHORIA_LOG("Registering Base Systems");
    Systems::System::RegisterBaseSystems();
    EUPHORIA_LOG("Registered Base Systems");

    EUPHORIA_LOG("Starting application");

    m_Window = std::make_unique<Window>(params.WindowCreationData, params.RuntimeInfo);
    if (RuntimeInfo.HeadlessMode) {
        EUPHORIA_WARNING("Engine has been started in headless mode, all rendering features WILL be disabled.");
    }
    else m_Window->CreateRenderer(params.RendererCreationData);

    Scene* scene = new Scene();
    scene->Load();

    std::shared_ptr<Object> object = Object::CreateObject("Sprite"); // this function auto registers itself with the active scene
    object->SetSprite(Euphoria::Rendering::Sprite::CreateSprite("C:\\Personal\\Coding\\Engines\\Euphoria\\Euphoria\\Resources\\Textures\\Image.png", sf::IntRect({ 0, 0 }, { 512, 512 }), sf::Vector2f(25, 25)));

    EUPHORIA_LOG("Creating physics world");
    Physics::Physics2D::CreateWorld();

    EUPHORIA_LOG("Initializing ImGui");
    if (!Rendering::Gui::InitializeContext(*m_Window->GetRenderer()->GetWindow())) {
        EUPHORIA_LOG("Failed to initialize ImGui context.");
        return;
    }

    EUPHORIA_LOG("Started application");
}

Application::~Application() = default;