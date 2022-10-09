#pragma once

#include "imgui/imgui.h"

namespace Application
{
	class UI
	{
	public:
		void displayUI();
	private:
		void menuBar();
		void WorldViewPort();
	};
}