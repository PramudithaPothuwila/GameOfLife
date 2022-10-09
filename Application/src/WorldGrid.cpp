#include "WorldGrid.h"
#include <cmath>

namespace GameOfLife
{
	WorldGrid::WorldGrid(int width)
	{
		grid = new int[width * width];
	}

	int WorldGrid::getWorldSize()
	{
		return gridWidth*gridWidth;
	}

	WorldGrid::~WorldGrid()
	{
		delete[] grid;
	}

	void WorldGrid::setCell(const int x,const int y,const int value)
	{
		grid[x * gridWidth + y] = value;
	}

	int WorldGrid::getCell(const int x,const int y)
	{
		return grid[x * gridWidth + y];
	}
}