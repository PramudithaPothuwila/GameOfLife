#pragma once

namespace game_of_life
{
	class WorldGrid
	{
		int m_grid_width;
		bool* m_grid;
	public:
		explicit WorldGrid(int width);
		~WorldGrid();
		void SetCell(int x, int y, bool value) const;
		[[nodiscard]] bool GetCell(int x, int y) const;
		int GetWorldWidth() const;
		[[nodiscard]] int GetWorldSize() const;
		bool* GetGrid() const;
		void Update_World(bool* new_grid);
		void Print() const;
	};
}
