#pragma once
#include <vector>
#include <memory>
#include "Euphoria/Core/Object.hpp"

namespace Euphoria::Core {
	class Scene {
	public:
		Scene();
		~Scene();

		void Load();
		void Unload();

		void AddObjectToScene(std::shared_ptr<Object> object) { Objects.push_back(object); }

		std::vector<std::shared_ptr<Object>> GetObjects() noexcept {
			return Objects;
		}

	public:
		static Scene* LoadedScene;

	private:
		std::vector<std::shared_ptr<Object>> Objects;
	};
}