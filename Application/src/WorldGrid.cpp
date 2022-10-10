#include "WorldGrid.h"
#include <cmath>
#include <iostream>
#include <thread>

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

	// Added for testing purposes
	void WorldGrid::print()
	{
		std::string frame;
		for (int i = 0; i < getWorldWidth(); i++)
		{
			for (int j = 0; j < getWorldWidth(); j++)
			{
				std::string cell = getCell(i, j) ? "1" : "0";
				frame.append(cell);
				frame.append(" ");
			}
			frame.append("\n");
		}
		std::cout << frame;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		system("CLS");
		
	}
}
