#pragma once

#define OPENGL 

#include <cstdio>
#include "console_ui.h"

#include "renderer.h"

namespace application
{
#ifdef OPENGL
	inline Renderer* Renderer_G = new Renderer_OpenGl();
#elif VULKAN
	inline Renderer* Renderer_G = new Renderer_Vulkan();
#else
	inline Renderer* Renderer_G = new Renderer_OpenGl();
#endif

	int init();
	int run();
	int shutdown();
}