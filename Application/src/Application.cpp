#include "Application.h"

#include "ComputeCPU.h"
#include "CudaRuntime.cuh"
#include "SystemState.h"


namespace Application
{
	GameOfLife::ThreadManager *thread_manager;
	int init()
	{
		SYSTEM_STATE = INIT;
		ConsoleUI::printMenu();
		return 0;
	}

	int run()
	{
		switch(MODE)
		{
		case CPU_SINGLE_THREAD:
			{
				thread_manager = new GameOfLife::ThreadManager(GRID);
				thread_manager->run();
				break;
			}
		case CPU_MULTI_THREAD:
			{
				thread_manager = new GameOfLife::ThreadManager(GRID);
				thread_manager->run();
				break;
			}
		case GPU_CUDA:
			{
				auto *compute_gpu = new Cuda_Runtime::ComputeGPU(GRID_WIDTH, GRID->getGrid());
				compute_gpu->run();
				break;
			}
		}
		return 0;
	}

	int shutdown()
	{
		return 0;
	}
}