#include "Application.h"
#include "ComputeCPU.h"

int main()
{
	Application::init();
	Application::run();
	Application::shutdown();
	
	//Temporary for testing
	// int gridSize = 75;
	//
	// const auto grid = new GameOfLife::WorldGrid(gridSize);
	// for(int i = 0; i < gridSize; i++)
	// {
	// 	if(i != 0)
	// 	{
	// 		for (int j = 0; j < gridSize; j++)
	// 		{
	// 			grid->setCell(i, j, false);
	// 		}
	// 		continue;
	// 	}
	// 	for (int j = 0; j < gridSize; j++)
	// 	{
	// 		grid->setCell(i, j, true);
	// 	}
	// }
	
	//
	// auto compute = new Cuda_Runtime::ComputeGPU(grid->getWorldWidth(),grid->getGrid());
	// compute->init();
	// compute->run();

	return 0;
}