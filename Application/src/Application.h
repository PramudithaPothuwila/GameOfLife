#pragma once

#define RENDERER 1

#include <cstdio>

#include <GLFW/glfw3.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include "renderer.h"

namespace Application
{
#ifdef RENDERER 0
	inline Renderer* renderer = new Renderer_OpenGl();
#else
	inline Renderer* renderer = new Renderer_Vulkan();
#endif
	int init();
	int run();
}