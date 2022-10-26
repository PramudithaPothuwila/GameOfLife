#pragma once
#include <string>
#include <opencv2/imgproc.hpp>

namespace Application
{
	class ImageProcessing
	{
	public:
		static void generateWorldFromImage(const std::string &path);
	private:
		static cv::Mat loadImage(const std::string &file);
	};
}
