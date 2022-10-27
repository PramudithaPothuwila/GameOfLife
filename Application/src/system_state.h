#pragma once
#include "world_grid.h"

enum State
{
	READY,
	RUNNING,
	SHUTDOWN
};
enum Mode
{
	CPU_SINGLE_THREAD,
	CPU_MULTI_THREAD,
	GPU_CUDA
};

inline State System_state_G;
inline State Cpu_state_G;
inline State Gpu_state_G;

inline Mode Mode_G;

inline int Grid_width_G;
inline int Grid_type_G; // 0 = randomly generated grid, 1 = grid from image file
inline game_of_life::WorldGrid *Grid_G;