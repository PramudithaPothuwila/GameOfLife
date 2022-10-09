#pragma once

#include <thread>

#include "WorldGrid.h"


namespace GameOfLife
{
	
	enum System_State
	{
		RUN,
		SHUTDOWN
	};

	enum Cell_State
	{
		DEAD,
		ALIVE
	};

	class ThreadManager
	{
	private:
		static WorldGrid* world_grid;
		static WorldGrid* world_buffer;
		static System_State SYSTEM_STATE;
	public:
		const static unsigned int processor_count_ = std::thread::hardware_concurrency();
		static void init(int width);
		static void run();
		static void shutdown();
	};

	class Thread
	{
	public:
		void Thread::run(WorldGrid* world_grid, WorldGrid* world_buffer,int startingPoint);
	};
	
}