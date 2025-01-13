
# PacMan Game

A classic **PacMan** game developed in C, using SDL2 for graphics and game functionality. In this game, you control PacMan, who navigates a maze, eats pellets, and avoids ghosts to score points.

## Demo
![PacMan Demo](resources/images/demo.png) 

## Features
- **Movement**: Control PacMan with keyboard inputs (Arrow keys or WASD).
- **Ghost AI**: Ghosts move around the maze and chase PacMan.
- **Scoring**: Earn points by eating pellets and avoiding ghosts.
- **Progressive Levels**: As you clear each level, the difficulty increases.
- **Graphics**: Includes a custom image for the game (pacman_image.png).

## Requirements
- **SDL2**: Make sure SDL2 is installed on your system.
- **CMake**: Used for building the project.
- **C Compiler**: GCC (or another compatible C compiler).

## Installation and Build Instructions

1. **Clone this repository**:

   ```bash
   git clone https://github.com/your-username/pacman.git
   ```

2. **Navigate to the project directory**:

   ```bash
   cd pacman
   ```

3. **Create a build directory**:

   ```bash
   mkdir build
   cd build
   ```

4. **Run CMake to configure the project**:

   ```bash
   cmake ..
   ```

5. **Build the project**:

   ```bash
   make
   ```

6. **Run the game**:

   ```bash
   ./pacman
   ```

## Project Structure

```
/pacman
    /bin                # Compiled executable files
    /build              # CMake build directory
    /include            # Header files
    /lib                # Libraries (if necessary)
    /resources
        /images
            pacman_image.png   # Game image
    /src                # Source files (main.c, game.c, player.c)
    CMakeLists.txt       # CMake build configuration
    SDL2.dll             # SDL2 dynamic library (for Windows)
    sdl2-config.cmake    # SDL2 configuration file
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
