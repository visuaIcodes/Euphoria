#pragma once
#include <vector>
#include <memory>
#include "Euphoria/Rendering/Sprite.hpp"

namespace Euphoria::Core {
	class Scene {
	public:
		Scene();
		~Scene();

		void Load();
		void Unload();

		std::vector<std::shared_ptr<Rendering::Sprite>> Sprites;

	public:
		static Scene* LoadedScene;
	};
}