#pragma once


namespace GameOfLife
{
	class Sector;

	class WorldGrid
	{
		int gridWidth;
		int* grid;
	public:
		
		WorldGrid(int width);
		~WorldGrid();
		void setCell(int x, int y, int value);
		int getCell(int x, int y);
		int getSectorCount();
		int getWorldWidth();
		
		
	};
	
	class SuperSector
	{
		WorldGrid *worldGrid;
		int superSector[25] = {0};
		
	protected:
		int getCellState(const int &x,const int &y) const;
		void setCellState(const int &x,const  int &y,const int state);

	public:
		SuperSector(int x, int y, WorldGrid world);
		~SuperSector();
	};
	
	class Sector : SuperSector
	{
		int getNeighbors(const int &x,const int &y) const;
		void updateCellState(int x, int y);
	public:
		Sector();
		Sector(int x, int y, const WorldGrid &world);
		void computeSector();
	};
}