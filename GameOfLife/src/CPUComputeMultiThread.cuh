#pragma once
#include <vector>

namespace GameOfLife
{
	class CpuComputeMultiThread
	{
	public:
		void Compute(std::vector<std::vector<int>> *world);
	private:
		void ComputeCell(std::vector<std::vector<int>> *worldSubSector, int x, int y);
		void ThreadManager(std::vector<std::vector<int>> *world);
		
	};
}