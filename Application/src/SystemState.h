#pragma once
#include "WorldGrid.h"

enum State
{
	INIT,
	RUNNING,
	SHUTDOWN
};
enum Mode
{
	CPU_SINGLE_THREAD,
	CPU_MULTI_THREAD,
	GPU_CUDA
};

inline State SYSTEM_STATE;
inline State CPU_STATE;
inline State GPU_STATE;

inline Mode MODE;

inline int GRID_WIDTH;
inline int GRID_TYPE; // 0 = randomly generated grid, 1 = grid from image file
inline GameOfLife::WorldGrid *GRID;