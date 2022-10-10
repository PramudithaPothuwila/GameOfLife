#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

enum System_State
{
	INIT,
	RUNNING,
	SHUTDOWN
};
// Global variable
System_State GPU_SYSTEM_STATE;

namespace Cuda_Runtime
{
	__global__ void compute(bool *primary_device_buffer, bool *secondary_device_buffer, int world_width);

	class ComputeGPU
	{
		bool *host_world_buffer;
		bool *primary_device_world_buffer;
		bool *secondary_device_world_buffer;
		int world_width;
		int buffer_size;
	public:
		ComputeGPU(int world_width, bool *start_world_frame);
		void init();
		void run();
		void shutdown();
	};
}