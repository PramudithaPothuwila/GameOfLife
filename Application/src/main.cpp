#include "Application.h"
#include "ComputeCPU.h"
#include "CudaRuntime.cuh"
#include "WorldGrid.h"
#include <ostream>


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
	// // GameOfLife::ThreadManager *thread_manager = new GameOfLife::ThreadManager(grid);
	// // thread_manager->run();
	//
	// auto compute = new Cuda_Runtime::ComputeGPU(grid->getWorldWidth(),grid->getGrid());
	// compute->init();
	// compute->run();

	return 0;
}