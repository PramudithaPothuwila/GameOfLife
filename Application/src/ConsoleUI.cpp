
#include "ConsoleUI.h"


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
		char mode_input;
		std::cin >> mode_input;
		switch(static_cast<int>(mode_input))
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
			std::cout << "Invalid mode, defaulting to CPU single thread";
			break;
		}
	}
}
