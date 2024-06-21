# Makefile

# Compiler
CXX = g++

# Source file
SOURCE = main.cpp grid.cpp particle.cpp

# Output file
OUTPUT = myprogram

# Compiler flags
CXXFLAGS = -std=c++17 -I/usr/local/include

# Linker flags
LDFLAGS = -L/usr/local/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

# Build and run rule
run: $(SOURCE)
	$(CXX) $(SOURCE) -o $(OUTPUT) $(CXXFLAGS) $(LDFLAGS) && ./$(OUTPUT)

# Clean rule
clean:
	rm -f $(OUTPUT)