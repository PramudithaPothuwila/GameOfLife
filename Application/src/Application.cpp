#include "Application.h"


namespace Application
{
	int init()
	{
		renderer->init();
		return 1;
	}

	int run()
	{
		renderer->start();
		return 1;
	}

	int shutdown()
	{
		renderer->shutdown();
		return 0;
	}
}