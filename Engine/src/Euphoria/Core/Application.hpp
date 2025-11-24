#pragma once
#include "GlobalStructs.hpp"
#include <memory>
#include "Euphoria/Layers/Stack.hpp"

namespace Euphoria::Core {
	class Window;

	class Application {
	public:
		Application(Global::ApplicationCreationData& params);
		~Application();

		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;

		static std::unique_ptr<Application> InitializeApplication(Global::ApplicationCreationData& params);
		void Start();

		Global::EuphoriaRuntimeInfo RuntimeInfo;

	protected:
		std::unique_ptr<Window> m_Window;
	};
}