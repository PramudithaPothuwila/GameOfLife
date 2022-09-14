#include "Application.cuh"

#include "ImageProcessing.cuh"

void Application::init()
{
    
}

int Application::run()
{
    ImageProcessing::LoadImage("C:\\Users\\Buddy365\\Pictures\\Me\\IMG_20211206_001341.jpg");
    return 0;
}

void Application::shutdown()
{
    
}
