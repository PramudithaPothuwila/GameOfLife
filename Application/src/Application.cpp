#include "Application.h"
#include "SystemState.h"


namespace Application
{
	int init()
	{
		SYSTEM_STATE = INIT;
		ConsoleUI::printMenu();
		return 0;
	}

	int run()
	{
		return 0;
	}

	int shutdown()
	{
		return 0;
	}
}