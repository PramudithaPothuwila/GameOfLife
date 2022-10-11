#include "WorldGeneration.h"

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

	void generateFromImage(const std::string &path)
	{
		GRID = new GameOfLife::WorldGrid(GRID_WIDTH);
		ImageProcessing::generateWorldFromImage(path);
	}
}