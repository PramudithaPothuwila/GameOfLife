#include "ComputeCPU.h"



namespace GameOfLife
{
	void ThreadManager::init(int width)
	{
		world_grid = new WorldGrid(width);
		world_buffer = new WorldGrid(width);
	}
	
	void ThreadManager::run()
	{
		while(SYSTEM_STATE == RUN)
		{
			std::thread threads[processor_count_];
			for(int i = 0; i < processor_count_; i++)
			{
				threads[i] = std::thread(Thread::run, &world_grid, &world_buffer,i*(world_grid->getWorldSize()/processor_count_));
			}
			for(int i = 0; i < processor_count_; i++)
			{
				threads[i].join();
			}
		}
	}

	void ThreadManager::shutdown()
	{
		
	}

	void Thread::run(WorldGrid* world_grid, WorldGrid* world_buffer,int startingPoint)
	{
		for(int i = startingPoint; i < startingPoint + (world_grid->getWorldSize()/ ThreadManager::processor_count_); i++)
		{
			int xCord = i % world_grid->getWorldWidth();
			int yCord = i / world_grid->getWorldWidth();
			int aliveNeighbours = 0;
			for(int j = -1; j < 2; j++)
			{
				for(int k = -1; k < 2; k++)
				{
					if(j == 0 && k == 0)
					{
						continue;
					}
					if(world_grid->getCell(xCord + j, yCord + k) == ALIVE)
					{
						aliveNeighbours++;
					}
				}
			}
		}
	}
}