#include "WorldGeneration.h"
#include <cstdlib>
#include "SystemState.h"

namespace Application
{
	void generateRandomWorld()
	{
		GRID = new GameOfLife::WorldGrid(grid_width_);
		for (int i = 0; i < grid_width_; i++)
		{
			for (int j = 0; j < grid_width_; j++)
			{
				GRID->setCell(i, j, static_cast<bool>(rand() % 2));
			}
		}		
	}
  
	void generateFromImage(const std::string &path)
	{
		GRID = new GameOfLife::WorldGrid(grid_width_);
		ImageProcessing::generateWorldFromImage(path);
	}
}