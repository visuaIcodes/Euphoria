#include "Euphoria/Layers/EngineLayer.hpp"
#include "Euphoria/Rendering/Renderer.hpp"
#include "Euphoria/UI/Gui.hpp"
#include "Euphoria/Scene/Scene.hpp"
#include "Euphoria/Layers/Stack.hpp"
#include "Euphoria/Submodules/Time.hpp"
#include "Euphoria/Physics/Physics2D.hpp"

using namespace Euphoria;
using namespace Core;
using namespace Global;
using namespace Rendering;
using namespace UI;
using namespace Layers;

EngineLayer::EngineLayer() {}
EngineLayer::~EngineLayer() {}

void EngineLayer::OnAttach() {
	EUPHORIA_LOG("Successfully initialized the engine layer");
}

void EngineLayer::OnDeattach() {

}

void EngineLayer::OnEvent(StackEvent eventCode) {
	if (eventCode == StackEvent::Update) {
		this->Update();
	}
}

void EngineLayer::Update() {
	Submodules::Time::Tick(); // tick time
	unsigned int fps = Submodules::Time::GetFramesPerSecond();
	Physics::Physics2D::Simulate(1.0f / fps);
}