# cub3D - 3D Raycasting Game Engine

![](https://img.shields.io/badge/Language-C-blue.svg)

![](https://img.shields.io/badge/42-School-000000.svg)

![](https://img.shields.io/badge/build-passing-brightgreen.svg)

> A simplified 3D game engine inspired by Wolfenstein 3D, built from scratch in C using raycasting techniques and minilibx for graphics rendering.
> 

## 🎮 Demo

**Gameplay Video:** [Watch Demo](https://your-demo-link.com/)

*Experience classic first-person 3D navigation with smooth raycasting graphics*

## ✨ Features

- 🎯 **Raycasting Engine** - Real-time 3D rendering using 2D raycasting algorithms
- 🎨 **Textured Walls** - Different textures for North, South, East, and West walls
- 🖱️ **Mouse Look** - Smooth camera rotation with mouse movement
- ⌨️ **WASD Controls** - Intuitive movement with keyboard input
- 🚪 **Collision Detection** - Realistic wall collision system
- 🗺️ **Map Parser** - Custom map format with configurable layouts
- 🎮 **60 FPS Rendering** - Smooth gameplay experience
- 🔄 **Real-time Graphics** - Live rendering without pre-computed frames

## 🛠️ Tech Stack

**Core Technologies:**

- **C** - Low-level programming for performance
- **MinilibX** - Minimalist graphics library for pixel manipulation
- **Raycasting Algorithm** - Mathematical 3D projection technique
- **Makefile** - Build automation

**Graphics Techniques:**

- DDA (Digital Differential Analyzer) algorithm
- Bresenham's line algorithm for wall detection
- Texture mapping and scaling
- Frame buffer management

## 🚀 Quick Start

### Prerequisites

- GCC compiler
- Make
- MinilibX library
- X11 development libraries (Linux)
- Xcode Command Line Tools (macOS)

### Installation

1. **Clone the repository**
    
    ```bash
    git clone https://github.com/yourusername/cub3D.git
    cd cub3D
    
    ```
    
2. **Install MinilibX (if not already installed)**
    
    ```bash
    # macOS
    git clone https://github.com/42Paris/minilibx-linux.git mlx
    
    # Linux
    sudo apt-get update
    sudo apt-get install gcc make xorg libxext-dev libbsd-dev
    
    ```
    
3. **Build the project**
    
    ```bash
    make
    
    ```
    
4. **Run the game**
    
    ```bash
    ./cub3D maps/map.cub
    
    ```
    

## 🎮 Controls

| Key | Action |
| --- | --- |
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` `→` | Rotate camera left/right |
| `Mouse` | Look around (mouse movement) |
| `ESC` | Exit game |

## 📁 Project Structure

```
cub3D/
├── src/
│   ├── main.c              # Program entry point
│   ├── parsing/            # Map file parsing
│   ├── raycasting/         # Core raycasting engine
│   ├── graphics/           # Rendering and display
│   ├── events/             # Keyboard and mouse handling
│   └── utils/              # Helper functions
├── includes/
│   └── cub3d.h            # Header definitions
├── maps/                  # Sample map files
├── textures/              # Wall texture images
├── mlx/                   # MinilibX library
├── Makefile
└── README.md

```

## 🗺️ Map Format

Maps are defined in `.cub` files with the following format:

```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

C 220,100,0
F 255,30,0

1111111111
1000000001
1000N00001
1000000001
1111111111

```

- `NO/SO/WE/EA`: Texture paths for each wall direction
- `C`: Ceiling color (RGB)
- `F`: Floor color (RGB)
- `1`: Wall, `0`: Empty space
- `N/S/E/W`: Player start position and orientation

## 🧮 Raycasting Algorithm

The engine implements a classic raycasting approach:

1. **Ray Generation** - Cast rays from player position at each screen column
2. **DDA Traversal** - Step through grid cells until hitting a wall
3. **Distance Calculation** - Compute perpendicular distance to avoid fisheye effect
4. **Wall Height** - Calculate wall slice height based on distance
5. **Texture Mapping** - Apply appropriate wall texture with scaling

## 🔧 Technical Details

### Performance Optimizations

- Integer-based calculations for speed
- Lookup tables for trigonometric functions
- Efficient memory management
- Double buffering for smooth rendering

### Mathematical Foundations

- Vector mathematics for ray direction
- Trigonometry for rotation and projection
- Linear interpolation for texture scaling

## 🧪 Testing

```bash
# Build and test with sample maps
make test

# Run with different map configurations
./cub3D maps/simple.cub
./cub3D maps/complex.cub
./cub3D maps/maze.cub

```

## 📱 Screenshots

<details>
<summary>Click to view screenshots</summary>

### Main Gameplay

### Different Textures

### Map Overview

</details>

## 🚀 Building and Compilation

```bash
# Standard build
make

# Clean object files
make clean

# Complete clean (including executable)
make fclean

# Rebuild everything
make re

# Debug build with symbols
make debug

```

## 🤝 Contributing

This project was developed as part of the 42 School curriculum. Contributions and improvements are welcome!

1. Fork the project
2. Create your feature branch (`git checkout -b feature/OptimizeRaycasting`)
3. Commit your changes (`git commit -m 'Optimize raycasting performance'`)
4. Push to the branch (`git push origin feature/OptimizeRaycasting`)
5. Open a Pull Request

## 📚 Learning Resources

- [Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [Wolfenstein 3D's map renderer](https://github.com/id-Software/wolf3d)
- [42 School cub3D Subject](https://cdn.intra.42.fr/pdf/pdf/960/en.subject.pdf)

## 📝 License

This project is part of the 42 School curriculum and follows their academic guidelines.

## 👨‍💻 Author

**Your Name**

- GitHub: [@yourusername](https://github.com/yourusername)
- 42 Intra: [your42login](https://profile.intra.42.fr/users/your42login)
- LinkedIn: [Your LinkedIn](https://linkedin.com/in/yourprofile)

## 🏆 42 School Project

This project is part of the 42 School common core curriculum, focusing on:

- **Computer Graphics** - Understanding 3D rendering principles
- **Algorithm Implementation** - Raycasting and DDA algorithms
- **C Programming** - Low-level memory management and optimization
- **Mathematical Application** - Practical use of trigonometry and vectors

**Grade:** [Your grade if you want to share]

---

⭐ **Enjoyed exploring this 3D engine? Give it a star!** ⭐