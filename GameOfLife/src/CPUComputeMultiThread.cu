#include "CPUComputeMultiThread.cuh"
#include <thread>
#include <iostream>


namespace GameOfLife
{
	void CPUComputeMultiThread::compute(grid *world)
	{
		
	}

	void CPUComputeMultiThread::computeCell(grid *worldSubSector, int x, int y)
	{
		
	}

	void CPUComputeMultiThread::worldSlicer(const grid *world, const std::vector<grid> *subSectors, int subSectorCount)
	{
		const int size = world->size();
		for(int outerX = 2; outerX < size; outerX + 3)
		{
			for(int outerY = 2; outerY < size; outerY + 3)
			{
				grid subSector;
				for(int innerX = -2; innerX < 3; innerX++)
				{
					std::vector<int> row;
					for(int innerY = -2; innerY < 3; innerY++)
					{
						switch(world->at(outerX + innerX).at(outerY + innerY))
						{
							case 0:
								row.push_back(0);
								break;
							case 1:
								row.push_back(1);
								break;
							default:
								row.push_back(0);
								break;
						}
					}
					subSector.push_back(row);
				}
				//subSectors->push_back(subSector);
			}
		}
	}

	void CPUComputeMultiThread::threadManager(const grid *world)
	{
		const unsigned int processor_count = std::thread::hardware_concurrency();
		const int subSectorCount = std::ceil(static_cast<double>(world->size() * world->size())/9);
		std::vector<grid> subSectors;
		worldSlicer(world, &subSectors, subSectorCount);

	}
}