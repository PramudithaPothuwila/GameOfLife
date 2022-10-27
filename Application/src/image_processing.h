#pragma once
#include <string>
#include <opencv2/imgproc.hpp>

namespace application
{
	class ImageProcessing
	{
	public:
		static void GenerateWorldFromImage(const std::string &path);
	private:
		static cv::Mat LoadImage(const std::string &file);
	};
}
