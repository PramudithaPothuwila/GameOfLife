#pragma once
#include <vector>

namespace GameOfLife
{
	typedef std::vector<std::vector<int>> grid;
	
	class CPUComputeMultiThread
	{
	public:
		static void compute(std::vector<std::vector<int>> *world);
	private:
		void computeCell(std::vector<std::vector<int>> *worldSubSector, int x, int y);
		static void threadManager(const std::vector<std::vector<int>> *world);
		static void worldSlicer(const std::vector<std::vector<int>> *world, const std::vector<grid> *subSectors, int subSectorCount);
	};
}