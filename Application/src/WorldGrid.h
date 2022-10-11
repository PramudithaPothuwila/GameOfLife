#pragma once

namespace GameOfLife
{
	class Sector;

	class WorldGrid
	{
		int gridWidth;
		bool* grid;
	public:
		explicit WorldGrid(int width);
		~WorldGrid();
		void setCell(int x, int y, bool value);
		bool getCell(int x, int y);
		int getWorldWidth();
		int getWorldSize();
		bool* getGrid();
		void print();
	};
}
