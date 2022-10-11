#pragma once
enum State
{
	INIT,
	RUNNING,
	SHUTDOWN
};


static State SYSTEM_STATE;
static State CPU_STATE;
static State GPU_STATE;