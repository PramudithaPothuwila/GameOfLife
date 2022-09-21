#pragma once


namespace GameOfLife
{
	class WorldGrid
	{
		static int gridWidth;
		static int *grid;
	public:
		WorldGrid(int width);
		~WorldGrid();
		static void setCell(int x, int y, int value);
		static int getCell(int x, int y);
		
	};
	
	class SuperSector
	{
		WorldGrid *worldGrid;
		int superSector[25];
		
	protected:
		int getCellState(const int &x,const int &y) const;
		void setCellState(const int &x,const  int &y,const int state);

	public:
		SuperSector(int x, int y);
		~SuperSector();
	};
	
	class Sector : SuperSector
	{
		int getNeighbors(const int &x,const int &y) const;
		void updateCellState(int x, int y);
	public:
		Sector(int x, int y);
		void computeSector();
	};
}