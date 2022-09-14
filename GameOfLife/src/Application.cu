#include "Application.cuh"
#include "ImageProcessing.cuh"
#include <iostream>
#include <vector>
#include <opencv2/core/utils/logger.hpp>


std::vector<std::vector<int>> world; // 2D vector to store the world

void Application::Application::init()
{
    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT); // Disable OpenCV logging
    int grid;
    std::cout << "Initializing application..." << std::endl;
    std::cout << "Enter the Grid: "; // Enter the grid size
    std::cin >> grid;
    world.reserve(grid); // Reserve the size of the grid
    std::cout << "If you want to enter the world manually, press 1. If you want to generate the world by image, press 2." << std::endl;
}

int Application::Application::run()
{
    ImageProcessing::LoadImage("C:\\Users\\Buddy365\\Pictures\\Me\\IMG_20211206_001341.jpg");
    return 0;
}

void Application::Application::shutdown()
{
    
}
