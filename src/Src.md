# 🔧 Source Code - Tetris Game

This directory contains the source code for the Tetris game implementation.

## 📁 Source Files Overview

| File | Purpose |
|------|---------|
| `main.cpp` | Entry point, window management, main game loop |
| `game.cpp/h` | Core game logic, state management, input handling |
| `grid.cpp/h` | Game grid implementation, line clearing mechanics |
| `block.cpp/h` | Individual tetromino (game piece) logic |
| `blocks.cpp` | Definitions of all 7 standard Tetris pieces |
| `colors.cpp/h` | Color definitions and utilities |
| `position.cpp/h` | Position handling and coordinate utilities |

## 🚀 Quick Compilation

### Linux/WSL:
```bash
g++ main.cpp grid.cpp colors.cpp position.cpp game.cpp block.cpp blocks.cpp \
    -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

### Windows (MinGW):
```bash
g++ main.cpp grid.cpp colors.cpp position.cpp game.cpp block.cpp blocks.cpp \
    -o main.exe -lraylib -lopengl32 -lgdi32 -lwinmm
```

## 🏃 Running the Game

### Linux/WSL:
```bash
./main
```

### Windows:
```bash
main.exe
```

## 📋 Prerequisites

1. **C++ Compiler** with C++14 support
2. **Raylib library** installed and accessible
3. **Required system libraries** (OpenGL, etc.)

## 🎮 Game Architecture

### Main Game Loop (`main.cpp`)
- Initializes window (500x620 pixels)
- Loads font and music
- Handles rendering and frame timing
- Event-driven piece movement (every 0.335 seconds)

### Game State Management (`game.cpp/h`)
- Manages current and next pieces
- Handles input processing
- Implements game logic and scoring
- Controls game over conditions

### Grid System (`grid.cpp/h`)
- 20x10 playing field
- Line detection and clearing
- Block placement validation

### Tetromino System (`block.cpp/h`, `blocks.cpp`)
- 7 standard Tetris pieces (I, O, T, S, Z, J, L)
- Rotation and movement mechanics
- Collision detection

## 🔧 Development Notes

- The game runs at 60 FPS
- Piece drop interval: 0.335 seconds
- Window size: 500x620 pixels
- Grid size: 10x20 cells
- Font: Monogram TTF (retro style)

## 🎨 Customization Points

- **Drop Speed**: Modify the interval in `EventTriggered()` call
- **Grid Size**: Update constants in grid.cpp/h
- **Colors**: Modify color definitions in colors.cpp/h
- **Window Size**: Change dimensions in `InitWindow()` call
- **Piece Definitions**: Edit shapes in blocks.cpp

## 🐛 Common Compilation Issues

1. **Raylib not found**: Ensure `-I` and `-L` flags point to Raylib installation
2. **Missing libraries**: Install development packages for your platform
3. **C++ standard**: Ensure compiler supports C++14 or later

## 📦 External Dependencies

- **Raylib**: Graphics, audio, and input handling
- **OpenGL**: Graphics rendering backend
- **System libraries**: Threading, math, dynamic linking (platform-specific)

---

**For the complete project documentation, see the main README.md file in the parent directory.**