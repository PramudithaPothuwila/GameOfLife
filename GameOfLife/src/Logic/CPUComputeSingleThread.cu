#include "CPUComputeSingleThread.cuh"

namespace GameOfLife
{
	void CPUComputeSingleThread::Compute(std::vector<std::vector<int>>  *world)
	{
		while(true)
		{
			computeNextGeneration(world);
		}
	}

	int CPUComputeSingleThread::getNeighbours(const std::vector<std::vector<int>> *world, int x, int y)
	{
		int neighbours = 0;

		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (i == 0 && j == 0)
					continue;

				if (x + i < 0 || x + i >= world->size())
					continue;

				if (y + j < 0 || y + j >= world->at(0).size())
					continue;

				if (world->at(x + i).at(y + j) == 1)
					neighbours++;
			}
		}
		return neighbours;
	}

	void CPUComputeSingleThread::computeNextGeneration(std::vector<std::vector<int>> *world)
	{
		const auto newWorld = new std::vector<std::vector<int>>(world->size(), std::vector<int>(world->size(), 0));
		for(int i = 0; i < world->size(); i++)
		{
			for(int j = 0; j < world->size(); j++)
			{
				const int neighbours = getNeighbours(world, i, j);
				if(neighbours < 2 || neighbours > 3)
				{
					(*newWorld)[i][j] = 0;
				}
				else if(neighbours == 3)
				{
					(*newWorld)[i][j] = 1;
				}
				else
				{
					(*newWorld)[i][j] = (*world)[i][j];
				}
			}
		}
		free(world);
		world = newWorld;
	}
}