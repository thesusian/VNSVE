CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
SHADERS_DIR = shaders

VulkanApp: shaders main.cpp 
	g++ $(CFLAGS) -o VulkanApp main.cpp $(LDFLAGS)

shaders: $(SHADERS_DIR)/shader.vert $(SHADERS_DIR)/shader.frag
	glslc $(SHADERS_DIR)/shader.vert -o $(SHADERS_DIR)vert.spv
	glslc $(SHADERS_DIR)/shader.frag -o $(SHADERS_DIR)frag.spv
	
run: VulkanApp
	./VulkanApp

clean:
	rm -f VulkanApp
