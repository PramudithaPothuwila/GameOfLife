#include "CPUComputeMultiThread.cuh"

#include <iostream>


namespace GameOfLife
{
	void CPUComputeMultiThread::compute(std::vector<std::vector<int>> *world)
	{
		
	}

	void CPUComputeMultiThread::computeCell(std::vector<std::vector<int>> *worldSubSector, int x, int y)
	{
		
	}

	void CPUComputeMultiThread::worldSlicer(const std::vector<std::vector<int>> *world, int slices)
	{
		auto *worldSlices = new std::vector<std::vector<int>>[slices];
		int size = world->size();

		std::cout << "Size: " << size << std::endl;
		
		// for(int i = 0; i < slices; i++)
		// {
		// 	for(int j = -2; j < 2; j++)
		// 	{
		// 		worldSlices[i].push_back(world->at(i + j));
		// 	}
		// }
		
	}

	void CPUComputeMultiThread::threadManager(std::vector<std::vector<int>> *world)
	{
		
	}
}