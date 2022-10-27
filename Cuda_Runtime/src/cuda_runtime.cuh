#pragma once

namespace cuda_runtime
{
	class ComputeGpu
	{
		bool* m_host_world_buffer;
		bool* m_primary_device_world_buffer;
		bool* m_secondary_device_world_buffer;
		int m_world_width;
		int m_buffer_size;
	public:
		ComputeGpu(int world_width, bool* start_world_frame);
		void Init();
		void Run();
		void Shutdown() const;
	};
	
}