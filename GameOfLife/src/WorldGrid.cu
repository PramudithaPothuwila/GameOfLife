#include "WorldGrid.cuh"

namespace GameOfLife
{
	WorldGrid::~WorldGrid()
	{
		for (auto worldrow : worldGrid)
		{
			worldrow.clear();
		}
		worldGrid.clear();
	}

	void WorldGrid::setWorldSize(int worldSize)
	{
		this->worldSize = worldSize;
	}

	void WorldGrid::pushSectorToSectorSpace(Sector& sector)
	{
		worldSectors.push_back(sector);
	}

	void WorldGrid::worldSlicer() const
	{
		for(int outerX = 2; outerX < this->worldSize; outerX + 3)
		{
			for(int outerY = 2; outerY < this->worldSize; outerY + 3)
			{
				wGrid sector;
				Sector tempSector;
				for(int innerX = -2; innerX < 3; innerX++)
				{
					std::vector<int> row;
					for(int innerY = -2; innerY < 3; innerY++)
					{
						switch(this->worldGrid.at(outerX + innerX).at(outerY + innerY))
						{
						case 0:
							row.push_back(0);
							break;
						case 1:
							row.push_back(1);
							break;
						default:
							row.push_back(0);
							break;
						}
					}
					sector.push_back(row);
					row.clear();
				}
				for(int i = 0; i < 5; i++)
				{
					for(int j; j < 5; j++)
					{
						tempSector.insertSector(i,j,sector.at(i).at(j));
					}
				}
				sector.clear();
				worldSectors.push_back(tempSector);
			}
		}
	}

	Sector::Sector()
	{
		
	}

	int Sector::getNeigbourCount(int xCord, int yCord)
	{
		{
			xCord++;
			yCord++;
			int count;
			for(int i = -1; i < 2; i++)
			{
				for(int j = -1; j < 2; j++)
				{
					if(!(i == 0 && j == 0))
					{
						if(sectorOuterSpace[i+xCord][j+yCord] == 1)
						{
							count++;
						}
					}
				}
			}
		}
	}

	void Sector::insertSector(int xCord, int yCord, int value)
	{
		this->sectorOuterSpace[xCord][yCord] = value;
	}
}