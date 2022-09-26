#include "WorldGrid.cuh"
#include <cmath>

namespace GameOfLife
{
	WorldGrid::WorldGrid(int width)
	{
		grid = new int[width * width];
		int sectorCount = pow(ceil(static_cast<double>(gridWidth) / 5),2);
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

	int WorldGrid::getSectorCount()
	{
		return pow(ceil(static_cast<double>(gridWidth) / 5),2);
	}

	int WorldGrid::getWorldWidth()
	{
		return gridWidth;
	}
	
	SuperSector::SuperSector(const int x,const int y, WorldGrid world)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				this->superSector[x+y*5] = world.getCell(x + i, y + j);
			}
		}
		
	}

	SuperSector::~SuperSector()
	{
		delete[] superSector;
	}
	
	int SuperSector::getCellState(const int &x,const int &y) const
	{
		return superSector[y*5+x];
	}

	void SuperSector::setCellState(const int& x, const int& y,const int state)
	{
		superSector[y*5+x] = state;
	}
	
	
	Sector::Sector(const int x,const int y, const WorldGrid world) : SuperSector(x,y, world)
	{
		
	}
	
	int Sector::getNeighbors(const int& x, const int& y) const
	{
		int neighbors = 0;
		for(int i = 0; i < 9; i++)
		{
			if(i ==4)
				continue;
			neighbors = neighbors + getCellState(x + i % 3, y + i / 3);
		}
		return 0;
	}

	void Sector::updateCellState(const int x,const int y)
	{
		const int neighbors = getNeighbors(x, y);
		if(getCellState(x, y) == 1)
		{
			if(neighbors < 2 || neighbors > 3)
			{
				setCellState(x, y, 0);
			}
		}
		else
		{
			if(neighbors == 3)
			{
				setCellState(x, y, 1);
			}
		}
	}

	void Sector::computeSector()
	{
		for(int i = 0; i < 9; i++)
		{
			updateCellState(i % 3, i / 3);
		}
	}
}