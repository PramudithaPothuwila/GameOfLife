#include "world_generation.h"
#include <cstdlib>
#include <string>

#include "image_processing.h"
#include "system_state.h"

namespace application
{
	void generate_random_world()
	{
		Grid_G = new game_of_life::WorldGrid(Grid_width_G);
		for (int i = 0; i < Grid_width_G; i++)
		{
			for (int j = 0; j < Grid_width_G; j++)
			{
				Grid_G->SetCell(i, j, static_cast<bool>(rand() % 2));
			}
		}		
	}
  
	void generate_from_image(const std::string &path)
	{
		Grid_G = new game_of_life::WorldGrid(Grid_width_G);
		ImageProcessing::GenerateWorldFromImage(path);
	}
}