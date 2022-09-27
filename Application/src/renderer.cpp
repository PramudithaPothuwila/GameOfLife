#include "renderer.h"
#include <iostream>

namespace Application
{
    void Renderer_OpenGl::error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }
    
    int Renderer_OpenGl::init()
    {
        if (!glfwInit()) return -1;
        
        glfwSetErrorCallback(error_callback);

        window = glfwCreateWindow(1280, 720, "Game of Life", NULL, NULL);
        const char* glsl_version = "#version 130";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        (void)io;
        
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui::StyleColorsDark();//Color Theme

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);
        return 1;
    }

    int Renderer_OpenGl::start()
    {
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        while (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            userInterface.displayUI(); //Display Interface
            
            //ImGui::ShowDemoWindow();

            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);
        }
        return 0;
    }

    int Renderer_OpenGl::shutdown()
    {
        return 0;
    }

    int Renderer_Vulkan::init()
    {
        return 0;
    }

    int Renderer_Vulkan::start()
    {
        return 0;
    }

    int Renderer_Vulkan::shutdown()
    {
        return 0;
    }

    void Renderer_Vulkan::error_callback(int error, const char* description)
    {
        
    }
    
}

