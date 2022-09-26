#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h> 

namespace Application
{
	class GUI
	{
	private:
		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
		GLFWwindow* window = nullptr;
		ImGuiIO& io;

	public:
		int init();
		void run();
		void shutdown();
	};
	
}