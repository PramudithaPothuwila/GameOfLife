#pragma once
#include <vector>

namespace GameOfLife
{
	class Sector;
	typedef std::vector<std::vector<int>> wGrid;

	class WorldGrid
	{
	public:
		void setWorldSize(int worldSize);
		void pushSectorToSectorSpace(Sector &worldRow);
		void WorldGrid::worldSlicer() const;
		~WorldGrid();
		
	private:
		int worldSize;
		wGrid worldGrid;
		int subSectorCount;
		std::vector<Sector> worldSectors;
	};

	class Sector
	{
	public:
		Sector();
		int getNeigbourCount(int xCord, int yCord);
		void Sector::insertSector(int xCord, int yCord, int value);
	private:
		int sectorOuterSpace[5][5] ={0};
	};
}
