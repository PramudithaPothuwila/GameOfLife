#include "Application.h"
#include "ComputeCPU.h"
#include "WorldGrid.h"


int main()
{
	//Application::init();
	//Application::run();
	
	//Temporary for testing
	const auto grid = new GameOfLife::WorldGrid(100);
	std::cout << sizeof(bool) << std::endl;
	for(int i = 0; i < 100; i++)
	{
		if(i != 0)
		{
			for (int j = 0; j < 100; j++)
			{
				grid->setCell(i, j, false);
			}
		}
		else
		{
			for (int j = 0; j < 100; j++)
			{
				grid->setCell(i, j, true);
			}
		}
	}
	GameOfLife::ThreadManager *thread_manager = new GameOfLife::ThreadManager(grid);
	thread_manager->run();
	return 0;
}