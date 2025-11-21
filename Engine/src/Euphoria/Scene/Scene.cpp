#include "Scene.hpp"
#include "Euphoria/Rendering/Renderer.hpp"

using namespace Euphoria;
using namespace Core;

Scene* Scene::LoadedScene = nullptr;

Scene::Scene() {}

Scene::~Scene() {
	for (auto sprite : Sprites) {
		sprite.reset();
	}

	Sprites.clear();
}

void Scene::Load() {
	if (LoadedScene != this) {
		if (LoadedScene != nullptr) {
			LoadedScene->Unload();
		}

		LoadedScene = this;
	}
}

void Scene::Unload() {}