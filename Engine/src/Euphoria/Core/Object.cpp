#include "Euphoria/Core/Object.hpp"
#include "Euphoria/Systems/System.hpp"
#include "Euphoria/Layers/Stack.hpp"
#include "Euphoria/Scene/Scene.hpp"

using namespace Euphoria;
using namespace Core;

Object::Object(std::string name) : Name(name) {}
Object:: ~Object() {}

void Object::OnAttach() {

}

void Object::OnDeattach() {

}

void Object::OnEvent(Global::StackEvent eventCode) {

}

std::shared_ptr<Object> Object::CreateObject(std::string name) {
	std::shared_ptr<Object> object = std::make_shared<Object>(name);
	if (Scene::LoadedScene) Scene::LoadedScene->AddObjectToScene(object);
	Systems::System::Get<LayerStack::Stack>()->PushLayer(object);
	return object;
}