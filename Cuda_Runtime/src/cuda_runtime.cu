#include "CudaRuntime.cuh"

 #include <cstdlib>
 #include <iostream>
 #include <string>
 #include <thread>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"


 namespace Cuda_Runtime
 {
 	__global__ void compute(const bool *primary_device_buffer, bool *secondary_device_buffer, int world_width)
 	{
        int index = blockIdx.x * blockDim.x +threadIdx.x;
 		const int x_cord = index % world_width;
 		const int y_cord = index / world_width;
 		int alive_neighbours = 0;
        for (int k = -1; k < 2; k++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (j == 0 && k == 0)
                {
                    continue;
                }
                if (primary_device_buffer[(y_cord + k) * world_width + (x_cord + j)] == true)
                {
                    alive_neighbours++;
                }
            }
        }
 		if(alive_neighbours < 2 || alive_neighbours > 3)
 		{
 			secondary_device_buffer[index] = false;
 		}
 		else if(alive_neighbours == 3)
 		{
 			secondary_device_buffer[index] = true;
 		}
 		else
 		{
 			secondary_device_buffer[index] = primary_device_buffer[index];
 		}
 	}

 	ComputeGPU::ComputeGPU(int world_width, bool *start_world_frame)
 	{
 		gpu_state_ = INIT;
 		this->world_width = world_width;
 		this->host_world_buffer = start_world_frame;
 	}

 	void ComputeGPU::init()
 	{
 		buffer_size = world_width * world_width * sizeof(bool);
 		//GPU device memory allocation
 		cudaMalloc(&primary_device_world_buffer, buffer_size);
 		cudaMalloc(&secondary_device_world_buffer, buffer_size);

 		//Copy world buffer to GPU device
 		cudaMemcpy(primary_device_world_buffer, host_world_buffer, buffer_size,cudaMemcpyHostToDevice);

        gpu_state_ = RUNNING;
 	}
 	
 	void ComputeGPU::run()
 	{
 		while(gpu_state_ == RUNNING)
 		{
 			compute <<< world_width, world_width >>>(primary_device_world_buffer, secondary_device_world_buffer, world_width);
 			cudaMemcpy(host_world_buffer, secondary_device_world_buffer, buffer_size,cudaMemcpyDeviceToHost);
 			cudaMemcpy(primary_device_world_buffer, secondary_device_world_buffer, buffer_size,cudaMemcpyDeviceToDevice);
 			GRID->update_world(host_world_buffer);
 			GRID->print();
 		}
 	}

 	void ComputeGPU::shutdown()
 	{
 		free(host_world_buffer);
 		cudaFree(primary_device_world_buffer);
 		cudaFree(secondary_device_world_buffer);
        gpu_state_ = SHUTDOWN;
 	}
}	