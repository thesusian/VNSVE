CC = g++
LIBS_DIR = ./libs
CFLAGS = -std=c++17 -I$(LIBS_DIR)/stb
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))
SHADERS_DIR = shaders

App: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o VulkanApp $(LDFLAGS)

$(OBJECTS): src/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

run: App 
	./VulkanApp

shader: $(SHADERS_DIR)/shader.*
	glslc $(SHADERS_DIR)/shader.vert -o $(SHADERS_DIR)/vert.spv
	glslc $(SHADERS_DIR)/shader.frag -o $(SHADERS_DIR)/frag.spv
	
clean:
	rm -f VulkanApp src/*.o
