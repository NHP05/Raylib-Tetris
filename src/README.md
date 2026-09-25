# 🎮 Tetris Game

A classic Tetris game implementation using C++ and Raylib graphics library.

![Tetris Preview](../preview.jpg)

## 📋 Table of Contents
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Building and Running](#building-and-running)
- [Game Controls](#game-controls)
- [Project Structure](#project-structure)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## ✨ Features

- Classic Tetris gameplay mechanics
- Score tracking system
- Next piece preview
- Smooth piece movement and rotation
- Game over detection
- Background music (Tetris theme)
- Clean, retro-style graphics
- Responsive controls

## 🔧 Requirements

- **C++ Compiler**: GCC or MinGW (C++14 standard)
- **Raylib**: Graphics and audio library
- **Operating System**: Windows, Linux, or macOS
- **Build Tools**: Make or MinGW32-make

### Dependencies
- OpenGL
- GLFW (for window management)
- Additional system libraries based on platform

## 🚀 Installation

### 1. Clone the Repository
```bash
git clone <repository-url>
cd Tetris
```

### 2. Install Raylib
Make sure you have Raylib installed on your system. You can download it from [raylib.com](https://www.raylib.com/) or install it using your package manager.

#### On Ubuntu/Debian:
```bash
sudo apt update
sudo apt install libraylib-dev
```

#### On Windows:
- Download Raylib from the official website
- Extract to a suitable location (e.g., `C:/raylib/`)
- Update the `RAYLIB_PATH` in the Makefile if necessary

## 🔨 Building and Running

### Using Makefile (Recommended)
The project includes a comprehensive Makefile that supports multiple platforms:

```bash
# Build the game
make

# Run the game
./game
```

### Manual Compilation
If you prefer to compile manually or need to customize the build:

#### On Linux:
```bash
cd src
g++ main.cpp grid.cpp colors.cpp position.cpp game.cpp block.cpp blocks.cpp \
    -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./main
```

#### On Windows (MinGW):
```bash
cd src
g++ main.cpp grid.cpp colors.cpp position.cpp game.cpp block.cpp blocks.cpp \
    -o main.exe -lraylib -lopengl32 -lgdi32 -lwinmm
main.exe
```

### Build Modes
The Makefile supports different build modes:

```bash
# Debug mode (with debug symbols)
make BUILD_MODE=DEBUG

# Release mode (optimized)
make BUILD_MODE=RELEASE
```

## 🎮 Game Controls

- **⬅️ Left Arrow**: Move piece left
- **➡️ Right Arrow**: Move piece right
- **⬇️ Down Arrow**: Soft drop (faster falling)
- **🔄 Up Arrow / Space**: Rotate piece
- **❌ ESC**: Quit game

## 📁 Project Structure

```
Tetris/
├── src/                    # Source code files
│   ├── main.cpp           # Main game loop and window management
│   ├── game.cpp/h         # Game logic and state management
│   ├── grid.cpp/h         # Game grid implementation
│   ├── block.cpp/h        # Individual block/tetromino logic
│   ├── blocks.cpp         # Tetromino definitions and types
│   ├── colors.cpp/h       # Color definitions and utilities
│   ├── position.cpp/h     # Position handling utilities
│   ├── raylib/            # Raylib library source (if included)
│   ├── Font/              # Game fonts
│   │   └── monogram.ttf   # Monospace font for UI
│   └── Sounds/            # Audio files
│       └── Tetris.mp3     # Background music
├── Font/                  # Additional font files
├── Sounds/                # Additional audio files
├── lib/                   # Required DLL files (Windows)
├── Makefile              # Build configuration
├── preview.jpg           # Game screenshot
└── README.md             # This file
```

## 🎯 Key Components

### Game Class (`game.cpp/h`)
- Manages overall game state
- Handles input processing
- Controls game logic and scoring
- Manages current and next pieces

### Grid Class (`grid.cpp/h`)
- Represents the game playing field
- Handles line clearing mechanics
- Manages placed blocks

### Block Classes (`block.cpp/h`, `blocks.cpp`)
- Defines tetromino shapes and behaviors
- Handles piece rotation and movement
- Contains all 7 standard Tetris pieces

## 🛠️ Development

### Adding New Features
1. Follow the existing code structure
2. Add new source files to the Makefile if needed
3. Maintain the separation of concerns between classes
4. Test thoroughly on your target platform

### Debugging
Use the debug build mode for development:
```bash
make BUILD_MODE=DEBUG
```

This includes debug symbols and disables optimizations for easier debugging.

## 🎨 Customization

- **Colors**: Modify `colors.cpp/h` to change the game's color scheme
- **Music**: Replace `Sounds/Tetris.mp3` with your preferred background music
- **Fonts**: Update font files in the `Font/` directory
- **Game Speed**: Adjust the interval in `main.cpp` (currently 0.335 seconds)

## 🐛 Troubleshooting

### Common Issues

1. **Raylib not found**: Ensure Raylib is properly installed and the `RAYLIB_PATH` in the Makefile points to the correct location
2. **Missing libraries**: Install all required dependencies for your platform
3. **Font/Music not loading**: Check that file paths are correct and files exist

### Platform-Specific Notes

- **Windows**: Ensure MinGW or appropriate compiler is in your PATH
- **Linux**: May require additional X11 development libraries
- **WSL**: Should work with X11 forwarding enabled

## 📝 License

This project is provided as-is for educational and entertainment purposes.

## 🤝 Contributing

Feel free to contribute to this project by:
- Reporting bugs
- Suggesting new features
- Submitting pull requests
- Improving documentation

---

**Enjoy playing Tetris! 🎮**