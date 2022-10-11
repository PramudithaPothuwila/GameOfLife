#include "ConsoleUI.h"
#include "WorldGeneration.h"

namespace Application
{
	void ConsoleUI::printMenu()
	{
		std::cout << "Enter grid size: ";
		std::cin >> GRID_WIDTH;
		std::cout << "Available modes of Operation: " << std::endl;
		std::cout << "1. CPU single thread" << std::endl;
		std::cout << "2. CPU multi thread" << std::endl;
		std::cout << "3. GPU CUDA" << std::endl;
		std::cout << "Enter mode of operation: ";
		int mode_input;
		std::cin >> mode_input;
		switch(mode_input)
		{
		case 1:
			MODE = CPU_SINGLE_THREAD;
			std::cout << "CPU single thread mode selected" << std::endl;
			break;
		case 2:
			MODE = CPU_MULTI_THREAD;
			std::cout << "CPU multi thread mode selected" << std::endl;
			break;
		case 3:
			MODE = GPU_CUDA;
			std::cout << "GPU CUDA mode selected" << std::endl;
			break;
		default:
			MODE = CPU_SINGLE_THREAD;
			std::cout << "Invalid mode selected, defaulting to CPU single thread mode" << std::endl;
			break;
		}
		
		std::cout << "Available world grids types:" << std::endl;
		std::cout << "1. Generate random grid" << std::endl;
		std::cout << "2. Generate grid from image file" << std::endl;
		std::cout << "Enter grid type: ";
		std::cin >> GRID_TYPE;
		switch(GRID_TYPE)
		{
		case 1:
			std::cout << "World grid is randomly generated" << std::endl;
			generateRandomWorld();
			break;
		case 2:
			std::cout << "Enter path for image for world generation:";
			std::string image_path;
			std::cin >> image_path;
			generateFromImage(image_path);
			break;
		}
	}
}
