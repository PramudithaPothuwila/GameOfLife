#pragma once

#include "imgui/imgui.h"

namespace application
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