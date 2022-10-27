#include "compute_cpu.h"
#include "system_state.h"


namespace game_of_life
{
	unsigned int Processor_count_G;
		
	void thread_work(const WorldGrid* world_grid, const WorldGrid* world_buffer, const int starting_point)
	{
		for(int i = starting_point; i < starting_point + world_grid->GetWorldSize() / Processor_count_G; i++)
		{
			const int x_cord = i % world_grid->GetWorldWidth();
			const int y_cord = i / world_grid->GetWorldWidth();
			
			int alive_neighbours = 0; 
			for(int j = -1; j < 2; j++)
			{
				for(int k = -1; k < 2; k++)
				{
					if(j == 0 && k == 0)
					{
						continue;
					}
					if(world_grid->GetCell(x_cord + j, y_cord + k) == ALIVE)
					{
						alive_neighbours++;
					}
				} 
			}
			if(alive_neighbours == 3) world_buffer->SetCell(x_cord, y_cord, ALIVE);
			else if(alive_neighbours == 2) world_buffer->SetCell(x_cord, y_cord, world_grid->GetCell(x_cord, y_cord));
			else world_buffer->SetCell(x_cord, y_cord, DEAD);
		}
	}
	

	ThreadManager::ThreadManager(WorldGrid* world_grid)
	{
		Cpu_state_G = READY;
		Init(world_grid);
	}

	void ThreadManager::Init(WorldGrid* _world_grid)
	{
		Cpu_state_G = RUNNING;
		switch(Mode_G)
		{
		case CPU_SINGLE_THREAD:
			Processor_count_G = 1;
			break;
		case CPU_MULTI_THREAD:
			Processor_count_G = std::thread::hardware_concurrency();
			break;
		default:
			Processor_count_G = 1;
			break;
		}
		world_grid = _world_grid;
		world_buffer = new WorldGrid(world_grid->GetWorldWidth());
	}
	
	void ThreadManager::Run()
	{
		while(Cpu_state_G == RUNNING)
		{
			const auto threads = new std::thread[Processor_count_G];
			
			// Initializing threads
			//int starting_point = i*(world_grid->getWorldSize()/processor_count)); <- This is the starting point for each thread. This was used in the previous version of the code. Now inlined
			for(int i = 0; i < Processor_count_G; i++) threads[i] = std::thread(thread_work, world_grid, world_buffer, i*(world_grid->GetWorldSize()/Processor_count_G));
			
			// Joining threads
			for(int i = 0; i < Processor_count_G; i++) threads[i].join();
			world_grid->Print();
			// Swap the buffers and threads clean up
			delete[] threads;
			//delete world_grid;
			world_grid = world_buffer;
			world_buffer = new WorldGrid(world_grid->GetWorldWidth());
		}
	}

	void ThreadManager::Shutdown() const
	{
		Cpu_state_G = SHUTDOWN;
		delete world_grid;
		delete world_buffer;
	}
}
