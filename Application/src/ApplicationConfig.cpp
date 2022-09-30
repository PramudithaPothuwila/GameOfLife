#include "ApplicationConfig.h"

namespace Application
{
	Config::Config()
	{
		cfg.readFile(output_file);
	}
	Config::~Config()
	{
		cfg.writeFile(output_file);
	}

	std::string Config::getSetting(std::string setting)
	{
		libconfig::Setting &root = cfg.getRoot();
		return root[setting];
	}

	void Config::setSetting(std::string setting, std::string value)
	{
		libconfig::Setting &root = cfg.getRoot();
	
		root.add(setting, libconfig::Setting::TypeString) = value;
	}
}