#include "cuda_runtime.cuh"
#include "system_state.h"

#include <cstdlib>
#include <iostream>
#include <thread>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"


namespace cuda_runtime
 {
 	__global__ void compute(const bool *primary_device_buffer, bool *secondary_device_buffer, int world_width)
 	{
	    const int index = blockIdx.x * blockDim.x +threadIdx.x;
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

 	ComputeGpu::ComputeGpu(const int world_width, bool *start_world_frame)
 	{
 		Gpu_state_G = READY;
 		this->m_world_width = world_width;
 		this->m_host_world_buffer = start_world_frame;
 	}

 	void ComputeGpu::Init()
 	{
 		m_buffer_size = m_world_width * m_world_width * sizeof(bool);
 		//GPU device memory allocation
 		cudaMalloc(&m_primary_device_world_buffer, m_buffer_size);
 		cudaMalloc(&m_secondary_device_world_buffer, m_buffer_size);

 		//Copy world buffer to GPU device
 		cudaMemcpy(m_primary_device_world_buffer, m_host_world_buffer, m_buffer_size,cudaMemcpyHostToDevice);

        Gpu_state_G = RUNNING;
 	}
 	
 	void ComputeGpu::Run()
 	{
 		while(Gpu_state_G == RUNNING)
 		{
 			compute <<< m_world_width, m_world_width >>>(m_primary_device_world_buffer, m_secondary_device_world_buffer, m_world_width);
 			cudaMemcpy(m_host_world_buffer, m_secondary_device_world_buffer, m_buffer_size,cudaMemcpyDeviceToHost);
 			cudaMemcpy(m_primary_device_world_buffer, m_secondary_device_world_buffer, m_buffer_size,cudaMemcpyDeviceToDevice);
 			Grid_G->Update_World(m_host_world_buffer);
 			Grid_G->Print();
 		}
 	}

 	void ComputeGpu::Shutdown() const
    {
 		free(m_host_world_buffer);
 		cudaFree(m_primary_device_world_buffer);
 		cudaFree(m_secondary_device_world_buffer);
        Gpu_state_G = SHUTDOWN;
 	}
}	