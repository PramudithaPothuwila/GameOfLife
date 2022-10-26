#include "world_grid.h"
#include <cmath>
#include <iostream>
#include <thread>

namespace game_of_life
{
	WorldGrid::WorldGrid(const int width)
	{
		m_grid_width = width;
		m_grid = new bool[width * width];
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < width; j++)
			{
				SetCell(i, j, false);
			}
		}
	}

	int WorldGrid::GetWorldSize() const
	{
		return m_grid_width*m_grid_width;
	}

	WorldGrid::~WorldGrid()
	{
		delete[] m_grid;
	}

	void WorldGrid::SetCell(const int x,const int y,const bool value) const
	{
		m_grid[x * m_grid_width + y] = value;
	}

	bool WorldGrid::GetCell(const int x,const int y) const
	{
		try
		{
			return m_grid[x * m_grid_width + y];
		}
		catch(...)
		{
			return false;
		}
	}

	int WorldGrid::GetWorldWidth() const
	{
		return m_grid_width;
	}

	bool* WorldGrid::GetGrid() const
	{
		return m_grid;
	}

	void WorldGrid::Update_World(bool* new_grid)
	{
		m_grid = new_grid;
	}
	
	void WorldGrid::Print() const
	{
		std::string frame;
		for (int i = 0; i < GetWorldWidth(); i++)
		{
			for (int j = 0; j < GetWorldWidth(); j++)
			{
				std::string cell = GetCell(i, j) ? "X" : " ";
				frame.append(cell);
				frame.append(" ");
			}
			frame.append("\n");
		}
		std::cout << frame;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		system("CLS");
		
	}
}
