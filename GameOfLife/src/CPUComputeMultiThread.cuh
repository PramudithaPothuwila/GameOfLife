#pragma once
#include <vector>

namespace GameOfLife
{
	class CPUComputeMultiThread
	{
	public:
		static void compute(std::vector<std::vector<int>> *world);
	private:
		static void computeCell(std::vector<std::vector<int>> *worldSubSector, int x, int y);
		static void threadManager(std::vector<std::vector<int>> *world);
		void worldSlicer(const std::vector<std::vector<int>> *world, int slices);
	};
}