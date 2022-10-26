#pragma once

#include <GLFW/glfw3.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include "renderer.h"
#include "ui.h"

namespace application
{
	class Renderer
	{
	public:
		GLFWwindow* window;
		UI userInterface;
		virtual int init() = 0;
		virtual int start() = 0;
		virtual int shutdown() = 0;
	};
	
	class Renderer_OpenGl: public Renderer
	{
	public:
		int init() override;
		int start() override;
		int shutdown() override;
	private:
		static void error_callback(int error, const char* description);
	};
	
	class Renderer_Vulkan: public Renderer
	{
	public:
		int init() override;
		int start() override;
		int shutdown() override;
	private:
		static void error_callback(int error, const char* description);
	};
}