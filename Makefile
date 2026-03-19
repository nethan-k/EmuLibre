# Compiler
CXX = g++

CXXFLAGS = -Wall -g

# Target executable
TARGET = main

# For deleting the target
TARGET_DEL = main

# Source files
SRCS = src/core/atari2600.cpp src/core/components/6502.cpp src/core/components/6532.cpp src/core/components/tia.cpp src/core/components/atari2600_bus.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files
clean:
	rm $(TARGET_DEL) $(OBJS)
