#include "WorldGeneration.h"
#include <cstdlib>

#include "SystemState.h"

namespace Application
{
	

	void generateRandomWorld()
	{
		GRID = new GameOfLife::WorldGrid(GRID_WIDTH);
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			for (int j = 0; j < GRID_WIDTH; j++)
			{
				GRID->setCell(i, j, static_cast<bool>(rand() % 2));
			}
		}		
	}

	void generateWorldFromImage()
	{
		GRID = new GameOfLife::WorldGrid(GRID_WIDTH);
		
	}
}