#pragma once

#include <cstdio>

#include <GLFW/glfw3.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_glfw.h"
#include "gui.h"

namespace Application
{
	int init();
	int run();
}