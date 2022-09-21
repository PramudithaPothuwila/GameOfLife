#include "WorldGrid.cuh"

namespace GameOfLife
{
	WorldGrid::WorldGrid(int width)
	{
		grid = new int[width * width];
	}

	WorldGrid::~WorldGrid()
	{
		delete[] grid;
	}

	SuperSector::SuperSector(int x, int y)
	{
		this->superSector = {0};
	}

	SuperSector::~SuperSector()
	{
		delete[] superSector;
	}

	void WorldGrid::setCell(const int x,const int y,const int value)
	{
		grid[y * gridWidth + x] = value;
	}

	int WorldGrid::getCell(const int x,const int y)
	{
		return grid[y * gridWidth + x];
	}
	
	int SuperSector::getCellState(const int &x,const int &y) const
	{
		return superSector[y*5+x];
	}

	void SuperSector::setCellState(const int& x, const int& y,const int state)
	{
		superSector[y*5+x] = state;
	}

	Sector::Sector(const int x,const int y) : SuperSector(x,y)
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