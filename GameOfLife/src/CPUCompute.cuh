#pragma once
#include <vector>


namespace GameOfLife
{
	class CPUCompute
	{
	public:
		static void Compute(int *world);
	private:
		static int getNeighbours(const std::vector<std::vector<int>> *world, int x, int y);
		static void computeNextGeneration(std::vector<std::vector<int>> *world);
	};
}