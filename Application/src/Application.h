#pragma once

#define OPENGL 

#include <cstdio>

#include <GLFW/glfw3.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include "renderer.h"

enum System_State
{
	INIT,
	RUNNING,
	SHUTDOWN
};

inline System_State SYSTEM_STATE;

namespace Application
{
#ifdef OPENGL
	inline Renderer* renderer = new Renderer_OpenGl();
#elif VULKAN
	inline Renderer* renderer = new Renderer_Vulkan();
#else
	inline Renderer* renderer = new Renderer_OpenGl();
#endif	
	int init();
	int run();
}