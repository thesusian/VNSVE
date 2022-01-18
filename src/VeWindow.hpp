#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <string>

namespace ve {
class VeWindow {        
    private:
        void initWindow();
        GLFWwindow *window;

        const int width;
        const int height;
        std::string windowName;
        
        bool framebufferResized = false;
        static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
            auto app = reinterpret_cast<VeWindow*>(glfwGetWindowUserPointer(window));
            app->framebufferResized = true;
            (void)(width);
            (void)(height);
        }

    public:
        VeWindow(int w, int h, std::string name);
        ~VeWindow();
      
        VeWindow(const VeWindow &) = delete;
        VeWindow &operator=(const VeWindow &) = delete;

        void resetWindowResized() {framebufferResized = false;}
        bool wasWindowResized() {return framebufferResized;}

        void handleMinimization();
        bool shouldClose() { return glfwWindowShouldClose(window); }

        void createSurface(VkInstance instance, VkSurfaceKHR *surface);
        void getFramebufferSize(int *w, int *h);
    };
}
