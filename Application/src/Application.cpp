#include "Application.h"

#include "ComputeCPU.h"
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
				thread_manager->run();
				break;
			}
		case CPU_MULTI_THREAD:
			{
				// Run multi threaded
				break;
			}
		case GPU_CUDA:
			{
				// Run single threaded
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