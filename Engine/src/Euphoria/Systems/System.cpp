#include "Euphoria/Systems/System.hpp"
#include "Euphoria/Layers/Stack.hpp"

using namespace Euphoria;
using namespace Systems;

void System::RegisterBaseSystems() {
    if (RegisteredBaseSystems) return;
    RegisteredBaseSystems = true;

    Add<LayerStack::Stack>();
}