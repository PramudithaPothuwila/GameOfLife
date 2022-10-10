#pragma once
#include "cuda_runtime.h"

namespace Cuda_Runtime
{
	__global__ void compute(bool *primary_device_buffer, bool *secondary_device_buffer);

	class ComputeGPU
	{
		bool *host_world_buffer;
		bool *primary_device_world_buffer;
		bool *secondary_device_world_buffer;
		int world_width;
	public:
		ComputeGPU(int world_width, bool *start_world_frame);
		void init();
		void run();
	};
}