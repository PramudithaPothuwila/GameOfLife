#pragma once
#include <cstdlib>
#include "ImageProcessing.h"
#include "SystemState.h"

namespace Application
{
	void generateRandomWorld();
	void generateFromImage(const std::string &path);
}