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

inline State system_state_;
inline State cpu_state_;
inline State gpu_state_;

inline Mode MODE;

inline int grid_width_;
inline int GRID_TYPE; // 0 = randomly generated grid, 1 = grid from image file
inline GameOfLife::WorldGrid *GRID;