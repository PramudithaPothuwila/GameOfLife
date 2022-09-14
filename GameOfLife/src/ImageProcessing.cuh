#pragma once
#include <string>
#include <opencv2/imgproc.hpp>

namespace GameOfLife
{
	class ImageProcessing
	{
	public:
		static void generateWorldFromImage(const std::string &path, std::vector<std::vector<int>> &world);
	private:
		static int loadImage(const std::string &filename);
	};
}
