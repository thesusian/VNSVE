# VNSVE
**a Very Nice Small Vulkan Engine**

****

### Requirements
  * apt
    * ```vulkan-tools```
    * ```libvulkan-dev```
    * ```vulkan-validationlayers-dev```
    * ```spirv-tools```
    * ```libglfw3-dev```
    * ```libglm-dev```
  * dnf
    * ```vulkan-tools```
    * ```vulkan-loader-devel```
    * ```spirv-tools```
    * ```vulkan-validation-layers-devel```
    * ```glfw-devel```
    * ```glm-devel```
  * pacman
    * ```vulkan-devel``` package group
    * ```glfw-x11``` or ```glfw-wayland```
    * ```glm```

### Building
  ```bash
  git clone https://github.com/thesusian/VNSVE.git
  cd VNSVE
  make
  ```
  then ```make run``` or ```./VulkanApp``` to run
