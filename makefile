CC = g++
LIBS_DIR = ./libs
CFLAGS = -std=c++17 -I$(LIBS_DIR)
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
SHADERS_DIR = shaders

App: src/*.cpp
	$(CC) $(CFLAGS) src/*.cpp -o VulkanApp $(LDFLAGS)

run: App 
	./VulkanApp

shader: $(SHADERS_DIR)/shader.*
	glslc $(SHADERS_DIR)/shader.vert -o $(SHADERS_DIR)/vert.spv
	glslc $(SHADERS_DIR)/shader.frag -o $(SHADERS_DIR)/frag.spv
	
clean:
	rm -f VulkanApp 
