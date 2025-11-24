#include <iostream>
#include "Euphoria/Core/Application.hpp"
#include "Euphoria/Layers/Stack.hpp"
#include "Core/EditorLayer.hpp"

using namespace Euphoria;
using namespace Core;
using namespace LayerStack;
using namespace Systems;

#define WINDOW_NAME "Euphoria Editor"
#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 512

int main() {
	Global::ApplicationCreationData creationData = {};
	creationData.RuntimeInfo.HeadlessMode = false;
	creationData.WindowCreationData.WindowWidth = WINDOW_WIDTH;
	creationData.WindowCreationData.WindowHeight = WINDOW_HEIGHT;
	creationData.WindowCreationData.WindowTitle = WINDOW_NAME;
	creationData.RendererCreationData.BackgroundData = Euphoria::Global::ClearColourData(25, 52, 62, 255);
	creationData.PathData.ResourcesDirectory = "C:\\Personal\\Coding\\Engines\\Euphoria\\Euphoria\\Resources";

	try {
		std::shared_ptr<Application> application = Application::InitializeApplication(creationData);
		System::Get<Stack>()->PushAndCreateLayer<EuphoriaEditor::Core::EditorLayer>(); // initialize and create the editor layer
		application->Start(); // begins the update loop
		return EXIT_SUCCESS;
	}
	catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
		return EXIT_FAILURE;
	}
}