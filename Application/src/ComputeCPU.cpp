#include "ComputeCPU.h"

namespace GameOfLife
{
	unsigned int processor_count = std::thread::hardware_concurrency() / 2;
		
	void ThreadWork(WorldGrid* world_grid, WorldGrid* world_buffer, int startingPoint)
	{
		for(int i = startingPoint; i < startingPoint + world_grid->getWorldSize()/ processor_count; i++)
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
			if(aliveNeighbours == 3)
			{
				world_buffer->setCell(xCord, yCord, ALIVE);
			}
			else if(aliveNeighbours == 2)
			{
				world_buffer->setCell(xCord, yCord, world_grid->getCell(xCord, yCord));
			}
			else
			{
				world_buffer->setCell(xCord, yCord, DEAD);
			}
		}
	}
	
	void ThreadManager::init(WorldGrid* worldgrid)
	{
		world_grid = worldgrid;
		world_buffer = new WorldGrid(world_grid->getWorldWidth());
		SYSTEM_STATE = RUN;
	}

	ThreadManager::ThreadManager(WorldGrid* world_grid)
	{
		SYSTEM_STATE = INIT;
		init(world_grid);
	}
	
	void ThreadManager::run()
	{
		int cycles = 0;
		while(SYSTEM_STATE == RUN)
		{
			std::thread *threads = new std::thread[GameOfLife::processor_count];
			for(int i = 0; i < GameOfLife::processor_count; i++)
			{
				int startingPoint = i*(world_grid->getWorldSize()/GameOfLife::processor_count);
				threads[i] = std::thread(ThreadWork, world_grid, world_buffer, startingPoint);
			}
			for(int i = 0; i < GameOfLife::processor_count; i++)
			{
				threads[i].join();
			}
			delete[] threads;
			//world_grid->Print();
			delete world_grid;

			world_grid = world_buffer;

			delete world_buffer;

			world_buffer = new WorldGrid(world_grid->getWorldWidth());
		}
	}

	void ThreadManager::shutdown()
	{
		SYSTEM_STATE = SHUTDOWN;
		delete world_grid;
		delete world_buffer;
	}
}