#pragma once

#include "world_grid.h"
#include "application.h"
#include <thread>
#include <iostream>
#include <vector>

enum Cell_State
{
	DEAD,
	ALIVE
};

namespace game_of_life
{
	
	class ThreadManager
	{
	private:
		WorldGrid* world_grid{};
		WorldGrid* world_buffer{};
	public:
		ThreadManager(WorldGrid *world_grid);
		~ThreadManager();
		void Init(WorldGrid* world_grid);
		void Run();
		void Shutdown() const;
	};
	
	void thread_work(const WorldGrid* world_grid, const WorldGrid* world_buffer,int starting_point);
}