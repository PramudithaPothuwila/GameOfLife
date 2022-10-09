#pragma once

#include <thread>
#include "WorldGrid.h"
#include <iostream>
#include <vector>

enum System_State
{
	INIT,
	RUN,
	SHUTDOWN
};

enum Cell_State
{
	DEAD,
	ALIVE
};

namespace GameOfLife
{
	class ThreadManager
	{
	private:
		WorldGrid* world_grid;
		WorldGrid* world_buffer;
		System_State SYSTEM_STATE;
	public:
		ThreadManager(WorldGrid *world_grid);
		~ThreadManager();
		void init(WorldGrid* world_grid);
		void run();
		void shutdown();
	};
	
	void ThreadWork(WorldGrid* world_grid, WorldGrid* world_buffer,int startingPoint);
}