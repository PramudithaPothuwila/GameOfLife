#include "ImageProcessing.cuh"

#include <iostream>


int ImageProcessing::LoadImage(const std::string &filename)
{
	cv::Mat image = imread(filename, cv::IMREAD_REDUCED_GRAYSCALE_8);// Read the file
	std::cout << image.cols<< " " << image.rows << std::endl;
	for(int i = 0; i < image.rows; i++)
	{
		for(int j = 0; j < image.cols; j++)
		{
			if(static_cast<double>(image.at<uchar>(i, j))/255 > 0.3)
			{
				//std::cout << (double)image.at<uchar>(i, j)/255 << std::endl;
				image.at<uchar>(i, j) = 255;
			}
			else
			{
				image.at<uchar>(i, j) = 0;
			}
		}
	}
	
	imshow("Display", image);
	cv::waitKey(0);
	return 0;
}
