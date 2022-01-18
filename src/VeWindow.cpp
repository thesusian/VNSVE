#include "VeWindow.hpp"

namespace ve {
    
    VeWindow::VeWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }
    
    VeWindow::~VeWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void VeWindow::initWindow() { 
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }

    void VeWindow::handleMinimization() {
        int w = 0;
        int h = 0;
        
        while (w == 0 || h == 0) {
            glfwGetFramebufferSize(window, &w, &h);
            glfwWaitEvents();
        }
    }

    void VeWindow::createSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("failed to create window surface!");
        } 
    }

    void VeWindow::getFramebufferSize(int *w, int *h) {
       glfwGetFramebufferSize(window, w, h); 
    }
}
