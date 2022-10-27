#include "image_processing.h"
#include "system_state.h"

#include <opencv2/highgui/highgui.hpp>
#include <iostream>

namespace application
{
	void ImageProcessing::GenerateWorldFromImage(const std::string &path)
	{
		cv::Mat image = LoadImage(path);
		const int rows = image.rows < Grid_width_G ? image.rows : Grid_width_G;
		const int cols = image.cols < Grid_width_G ? image.cols : Grid_width_G;
		for(int i = 0; i <  rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(image.at<uchar>(i, j) == 255)
				{
					Grid_G->SetCell(i, j, true);
				}
				else
				{
					Grid_G->SetCell(i, j, false);
				}
			}
		}
	}

	cv::Mat ImageProcessing::LoadImage(const std::string& file)
	{
		cv::Mat image = imread(file, cv::IMREAD_REDUCED_GRAYSCALE_8);
		std::cout << image.cols<< " " << image.rows << std::endl;
		for(int i = 0; i < image.rows; i++)
		{
			for(int j = 0; j < image.cols; j++)
			{
				if(static_cast<double>(image.at<uchar>(i, j))/255 > 0.3)
				{
					image.at<uchar>(i, j) = 255;
				}
				else
				{
					image.at<uchar>(i, j) = 0;
				}
			}
		}
		return image;
	}
}



