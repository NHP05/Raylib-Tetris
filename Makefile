# Raylib Tetris Makefile
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wno-missing-braces
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRC_DIR = src
RAYLIB_DIR = $(SRC_DIR)/raylib/src
BUILD_DIR = build

# Target executable
TARGET = game

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/game.cpp \
          $(SRC_DIR)/grid.cpp \
          $(SRC_DIR)/blocks.cpp \
          $(SRC_DIR)/block.cpp \
          $(SRC_DIR)/position.cpp \
          $(SRC_DIR)/colors.cpp

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Include directories
INCLUDES = -I$(RAYLIB_DIR) -I$(SRC_DIR)

# Default target
all: $(TARGET)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Install raylib (if needed)
install-raylib:
	sudo apt update
	sudo apt install libraylib-dev

# Run the game
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)

# Release build
release: CXXFLAGS += -O3 -DNDEBUG
release: $(TARGET)

.PHONY: all clean install-raylib run debug release