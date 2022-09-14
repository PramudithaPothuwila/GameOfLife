#include "ImageProcessing.cuh"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

namespace GameOfLife
{
	void ImageProcessing::generateWorldFromImage(const std::string &path, std::vector<std::vector<int>> &world)
	{
		cv::Mat image = loadImage(path);
		for(int i = 0; i < image.rows; i++)
		{
			for(int j = 0; j < image.cols; j++)
			{
				if(image.at<uchar>(i, j) == 255)
				{
					world[i][j] = 1;
				}
				else
				{
					world[i][j] = 0;
				}
			}
		}
	}

	cv::Mat ImageProcessing::loadImage(const std::string& filename)
	{
		cv::Mat image = imread(filename, cv::IMREAD_REDUCED_GRAYSCALE_8);// Read the file
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
	
		// imshow("Display", image);
		cv::waitKey(0);
		return image;
	}
}



