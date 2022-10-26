﻿#include "ImageProcessing.h"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "SystemState.h"
#include "WorldGrid.h"

namespace Application
{
	void ImageProcessing::generateWorldFromImage(const std::string &path)
	{
		cv::Mat image = loadImage(path);
		const int rows = image.rows < grid_width_ ? image.rows : grid_width_;
		const int cols = image.cols < grid_width_ ? image.cols : grid_width_;
		for(int i = 0; i <  rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(image.at<uchar>(i, j) == 255)
				{
					GRID->setCell(i, j, true);
				}
				else
				{
					GRID->setCell(i, j, false);
				}
			}
		}
	}

	cv::Mat ImageProcessing::loadImage(const std::string& file)
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



