CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
SHADERS_DIR = shaders

App: main.cpp 
	g++ $(CFLAGS) -o VulkanApp main.cpp $(LDFLAGS)

run: App 
	./VulkanApp

shader: $(SHADERS_DIR)/shader.*
	glslc $(SHADERS_DIR)/shader.vert -o $(SHADERS_DIR)/vert.spv
	glslc $(SHADERS_DIR)/shader.frag -o $(SHADERS_DIR)/frag.spv
	
clean:
	rm -f VulkanApp shaders/*.spv
