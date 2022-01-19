#pragma once

#include "VeWindow.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <vector>
#include <optional>
#include <set>

namespace ve {

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class VeDevice {
    
    private:
        void setupDebugMessenger();
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        void createInstance();
        void pickPhysicalDevice();
        void createLogicalDevice();
        void createCommandPool();
        void createSurface();
        void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
        bool isDeviceSuitable(VkPhysicalDevice device);
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);
        bool checkValidationLayerSupport();
        std::vector<const char*> getRequiredExtensions();
        VkDebugUtilsMessengerEXT debugMessenger;
        VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
        VkSampleCountFlagBits getMaxUsableSampleCount();

        const std::vector<const char*> validationLayers = {"VK_LAYER_KHRONOS_validation"};
        const std::vector<const char*> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
            if (messageSeverity == VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT) {
                //std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
            } else { 
                std::cerr << "\nvalidation layer: " << pCallbackData->pMessage << std::endl;
                std::cerr << "Severity: " << messageSeverity << " Type: " << messageType << "\n"; 
            }
            (void)(pUserData);
            return VK_FALSE;
        }

        VeWindow &window;
        VkInstance instance_;
        VkPhysicalDevice physicalDevice_ = VK_NULL_HANDLE;
        VkSampleCountFlagBits msaaSamples_ = VK_SAMPLE_COUNT_1_BIT;
        VkDevice device_;
        VkSurfaceKHR surface_;
        VkCommandPool commandPool_; 
        VkQueue graphicsQueue_;
        VkQueue presentQueue_;

    public:
        VeDevice(VeWindow &window);
        ~VeDevice();

        VeDevice(const VeDevice &) = delete;
        VeDevice &operator=(const VeDevice &) = delete;
        VeDevice(VeDevice &&) = delete;
        VeDevice &operator=(VeDevice &&) = delete;
        
        VkInstance instance() {return instance_;}
        VkPhysicalDevice physicalDevice() {return physicalDevice_;}
        VkSampleCountFlagBits msaaSamples() {return msaaSamples_;}
        VkDevice device() {return device_;}
        VkSurfaceKHR surface() {return surface_;}
        VkCommandPool commandPool() {return commandPool_;}
        VkQueue graphicsQueue() {return graphicsQueue_;}
        VkQueue presentQueue() {return presentQueue_;}

        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

};
}
