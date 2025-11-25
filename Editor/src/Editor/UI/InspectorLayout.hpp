#pragma once
#include "ImGui/imgui.h"
#include "Editor/UI/EditorUILayout.hpp"

namespace EuphoriaEditor::UI {
	class InspectorLayout : public EditorUILayout {
	public:
		~InspectorLayout() {}

		//ImGuiDir GetDockPosition() override {
		//	return ImGuiDir_Right;
		//}

		void Render() override {
			ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;

			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			ImGui::Begin("Inspector", nullptr, flags);
			ImGui::End();
			ImGui::PopStyleVar(2);
		}
	};
}