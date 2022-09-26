﻿#include "Application.cuh"
#include "ImageProcessing.cuh"
#include <iostream>
#include <vector>
#include <opencv2/core/utils/logger.hpp>
#include "CPUComputeMultiThread.cuh"
#include "CPUComputeSingleThread.cuh"


static std::vector<std::vector<int>> world; // 2D vector to store the world

namespace GameOfLife
{
	void Application::init()
	{
		setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT); // Disable OpenCV logging
		int grid;
		int gen_method;
		std::cout << "Initializing application..." << std::endl;
		std::cout << "Enter the Grid Size: "; // Enter the grid size
		std::cin >> grid;
		world.reserve(grid); // Reserve the size of the grid
		std::cout << "If you want to generate a random world, enter 1. If you want to generate a world from a image, enter 2: ";
		std::cin >> gen_method;
		if(gen_method == 1)
		{
			std::cout << "Generating random world..." << std::endl;
			for(int i = 0; i < grid; i++)
			{
				std::vector<int> row;
				row.reserve(grid);
				for(int j = 0; j < grid; j++)
				{
					row.push_back(rand() % 2); // Generate a random number between 0 and 1
				}
				world.push_back(row);
			}
		}
		else if(gen_method == 2)
		{
			std::string path;
			std::cout << "Enter the path to the image: ";
			std::cin >> path;
			ImageProcessing::generateWorldFromImage(path, world);
		}
		else
		{
			std::cout << "Invalid input. Exiting..." << std::endl;
			exit(0);
		}
		
	}

	int Application::run()
	{
		//GUI::run();
		return 0;
	}

	void Application::shutdown()
	{

	}
};

