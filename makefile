CFLAGS = -std=c++17 -O2
CC = g++
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
SHADERS_DIR = src/Shaders
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

App: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o VulkanApp $(LDFLAGS)

$(OBJECTS): src/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

run: App 
	./VulkanApp

shaders: $(SHADERS_DIR)/shader.*
	glslc $(SHADERS_DIR)/shader.vert -o $(SHADERS_DIR)/vert.spv
	glslc $(SHADERS_DIR)/shader.frag -o $(SHADERS_DIR)/frag.spv
	
clean:
	rm -f VulkanApp src/*.o
