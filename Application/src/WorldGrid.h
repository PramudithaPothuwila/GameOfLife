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
		int getWorldSize();
	};
}