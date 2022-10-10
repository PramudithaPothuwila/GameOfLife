#include "CudaRuntime.cuh"

namespace Cuda_Runtime
{
	__global__ void compute(bool *primary_device_buffer, bool *secondary_device_buffer)
	{
		
	}

	ComputeGPU::ComputeGPU(int world_width, bool *start_world_frame)
	{
		this->world_width = world_width;
		this->host_world_buffer = start_world_frame;
	}

	void ComputeGPU::init()
	{
		const int buffer_size = world_width * world_width * sizeof(bool);
		//GPU device memory allocation
		cudaMalloc(&primary_device_world_buffer, buffer_size);
		cudaMalloc(&secondary_device_world_buffer, buffer_size);

		//Copy world buffer to GPU device
		cudaMemcpy(primary_device_world_buffer, host_world_buffer, buffer_size,cudaMemcpyHostToDevice);
	}
}