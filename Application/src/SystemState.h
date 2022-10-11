#pragma once
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


static State SYSTEM_STATE;
static State CPU_STATE;
static State GPU_STATE;

static Mode MODE;

static int GRID_WIDTH;