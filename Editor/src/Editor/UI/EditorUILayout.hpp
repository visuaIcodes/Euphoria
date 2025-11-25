#pragma once
#include "ImGui/imgui.h"

namespace EuphoriaEditor::UI {
	class EditorUILayout {
	public:
		~EditorUILayout() {}

		virtual void Render() = 0;
	};
}