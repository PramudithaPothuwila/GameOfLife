#include "Application.h"
#include "ComputeCPU.h"
#include "WorldGrid.h"


int main()
{
	//Application::init();
	//Application::run();
	
	//Temporary for testing
	int gridSize = 50;
	
	const auto grid = new GameOfLife::WorldGrid(gridSize);
	std::cout << sizeof(bool) << std::endl;
	for(int i = 0; i < gridSize; i++)
	{
		if(i != 0)
		{
			for (int j = 0; j < gridSize; j++)
			{
				grid->setCell(i, j, false);
			}
			continue;
		}
		for (int j = 0; j < gridSize; j++)
		{
			grid->setCell(i, j, true);
		}
	}
	GameOfLife::ThreadManager *thread_manager = new GameOfLife::ThreadManager(grid);
	thread_manager->run();
	return 0;
}