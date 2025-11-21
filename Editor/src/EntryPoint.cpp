#include <iostream>
#include "Euphoria/Core/Application.hpp"

using namespace Euphoria;
using namespace Core;

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

	std::shared_ptr<Application> application = Application::InitializeApplication(creationData);
	try {
		application->Start();
		return EXIT_SUCCESS;
	}
	catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
		return EXIT_FAILURE;
	}
}