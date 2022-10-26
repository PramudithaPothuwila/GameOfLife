#pragma once

#include <string>
#include "SystemState.h"


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