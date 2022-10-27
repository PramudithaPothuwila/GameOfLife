#include "Application.h"

#include "compute_cpu.h"
#include "cuda_runtime.cuh"
#include "system_state.h"


namespace application
{
	// int init()
	// {
	// 	renderer->init();
	// 	return 0;
	// }
	//
	// int run()
	// {
	// 	renderer->start();
	// 	return 0;
	// }
	//
	// int shutdown()
	// {
	// 	renderer->shutdown();
	// 	return 0;
	// }

	game_of_life::ThreadManager *thread_manager;
	int init()
	{
		System_state_G = READY;
		ConsoleUI::PrintMenu();
		return 0;
	}
	
	int run()
	{
		switch(Mode_G)
		{
		case CPU_SINGLE_THREAD:
			{
				thread_manager = new game_of_life::ThreadManager(Grid_G);
				thread_manager->Run();
				break;
			}
		case CPU_MULTI_THREAD:
			{
				thread_manager = new game_of_life::ThreadManager(Grid_G);
				thread_manager->Run();
				break;
			}
		case GPU_CUDA:
			{
				auto *compute_gpu = new cuda_runtime::ComputeGpu(Grid_width_G, Grid_G->GetGrid());
				compute_gpu->Init();
				compute_gpu->Run();
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