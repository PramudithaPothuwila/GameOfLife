#pragma once

#include "libconfig/libconfig.h++"
#include <iostream>
#include <iomanip>
#include <cstdlib>


namespace Application
{
	class Config
	{
	private:
		static const char *output_file;
		libconfig::Config cfg;
		
		
	public:
		Config();
		~Config();
		std::string getSetting(std::string setting);
		void setSetting(std::string setting, std::string value);
	};
}
