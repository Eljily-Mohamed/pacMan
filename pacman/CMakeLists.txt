cmake_minimum_required(VERSION 3.29)
project(pacman C)

set(CMAKE_C_STANDARD 23)

# Set SDL2_DIR path for finding SDL2 (make sure SDL2 is installed)
set(SDL2_DIR /usr/include/SDL2)

# Copy SDL2.dll and resources only for Windows (optional)
# No need for Windows-specific code here
# file(COPY bin/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
# file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Source files
set(
    SRCS
    src/main.c
    src/framework.c
    src/firstLevel.c
    src/fantomes.c
)

# Header files
set(
    HEADER
    src/main.h
    src/framework.h
    src/firstLevel.h
    src/fantomes.h
)

# Find SDL2 package (ensure SDL2 is installed)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Create executable
add_executable(pacman ${SRCS} ${HEADER})

# Link SDL2 library
target_link_libraries(pacman ${SDL2_LIBRARIES})
