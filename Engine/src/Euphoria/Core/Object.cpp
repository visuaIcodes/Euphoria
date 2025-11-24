#include "Euphoria/Core/Object.hpp"
#include "Euphoria/Systems/System.hpp"
#include "Euphoria/Layers/Stack.hpp"
#include "Euphoria/Scene/Scene.hpp"

using namespace Euphoria;
using namespace Core;

Object::Object(std::string name) : Name(name) {
	Position = sf::Vector2f(0, 0);
	Size = sf::Vector2f(1, 1);
}

Object::~Object() {}

void Object::OnAttach() {

}

void Object::OnDeattach() {

}

void Object::OnEvent(Global::StackEvent eventCode) {
	if (eventCode == Global::StackEvent::Update) {
		if (Sprite != nullptr) 
			Sprite->ApplyTransformations(Position, Size, Rotation); // Apply transformations to sprite
	}
}

std::shared_ptr<Object> Object::CreateObject(std::string name) {
	std::shared_ptr<Object> object = std::make_shared<Object>(name);
	if (Scene::LoadedScene) Scene::LoadedScene->AddObjectToScene(object);
	Systems::System::Get<LayerStack::Stack>()->PushLayer(object);
	return object;
}