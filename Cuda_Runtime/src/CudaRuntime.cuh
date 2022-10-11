#pragma once
#include <string>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

// enum GPU_System_State
// {
// 	GPU_INIT,
// 	GPU_RUNNING,
// 	GPU_SHUTDOWN
// };
// // Global variable
// GPU_System_State GPU_SYSTEM_STATE;

namespace Cuda_Runtime
{
	class ComputeGPU
	{
		bool* host_world_buffer;
		bool* primary_device_world_buffer;
		bool* secondary_device_world_buffer;
		int world_width;
		int buffer_size;
	public:
		ComputeGPU(int world_width, bool* start_world_frame);
		void init();
		void run();
		void shutdown();
	};
	
}