#pragma once

#include "WorldGrid.h"
#include <thread>
#include <iostream>
#include <vector>

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
		WorldGrid* world_grid{};
		WorldGrid* world_buffer{};
	public:
		ThreadManager(WorldGrid *world_grid);
		~ThreadManager();
		void init(WorldGrid* world_grid);
		void run();
		void shutdown() const;
	};
	
	void ThreadWork(WorldGrid* world_grid, WorldGrid* world_buffer,int starting_point);
}