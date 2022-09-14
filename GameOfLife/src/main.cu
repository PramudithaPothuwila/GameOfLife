#include "Application.cuh"

int main()
{
	GameOfLife::Application::init();
	GameOfLife::Application::run();
	GameOfLife::Application::shutdown();
}