#include "WorldGrid.h"
#include <cmath>
#include <iostream>
#include <ostream>

namespace GameOfLife
{
	WorldGrid::WorldGrid(int width)
	{
		gridWidth = width;
		grid = new bool[width * width];
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < width; j++)
			{
				setCell(i, j, false);
			}
			std::cout << std::endl;
		}
	}

	int WorldGrid::getWorldSize()
	{
		return gridWidth*gridWidth;
	}

	WorldGrid::~WorldGrid()
	{
		delete[] grid;
	}

	void WorldGrid::setCell(const int x,const int y,const bool value)
	{
		grid[x * gridWidth + y] = value;
	}

	bool WorldGrid::getCell(const int x,const int y)
	{
		try
		{
			return grid[x * gridWidth + y];
		}
		catch(...)
		{
			return false;
		}
	}

	int WorldGrid::getWorldWidth()
	{
		return gridWidth;
	}

	void WorldGrid::print()
	{
		for (int i = 0; i < getWorldWidth(); i++)
		{
			for (int j = 0; j < getWorldWidth(); j++)
			{
				std::cout << getCell(i, j) << " ";
			}
			std::cout << std::endl;
		}
	}
}
