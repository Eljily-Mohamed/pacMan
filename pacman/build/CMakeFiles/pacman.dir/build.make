# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/eljily/Desktop/projects./projects/pacman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/eljily/Desktop/projects./projects/pacman/build

# Include any dependencies generated for this target.
include CMakeFiles/pacman.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pacman.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pacman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pacman.dir/flags.make

CMakeFiles/pacman.dir/codegen:
.PHONY : CMakeFiles/pacman.dir/codegen

CMakeFiles/pacman.dir/src/main.c.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/main.c.o: /home/eljily/Desktop/projects./projects/pacman/src/main.c
CMakeFiles/pacman.dir/src/main.c.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/eljily/Desktop/projects./projects/pacman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pacman.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/main.c.o -MF CMakeFiles/pacman.dir/src/main.c.o.d -o CMakeFiles/pacman.dir/src/main.c.o -c /home/eljily/Desktop/projects./projects/pacman/src/main.c

CMakeFiles/pacman.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pacman.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eljily/Desktop/projects./projects/pacman/src/main.c > CMakeFiles/pacman.dir/src/main.c.i

CMakeFiles/pacman.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pacman.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eljily/Desktop/projects./projects/pacman/src/main.c -o CMakeFiles/pacman.dir/src/main.c.s

CMakeFiles/pacman.dir/src/framework.c.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/framework.c.o: /home/eljily/Desktop/projects./projects/pacman/src/framework.c
CMakeFiles/pacman.dir/src/framework.c.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/eljily/Desktop/projects./projects/pacman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/pacman.dir/src/framework.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/framework.c.o -MF CMakeFiles/pacman.dir/src/framework.c.o.d -o CMakeFiles/pacman.dir/src/framework.c.o -c /home/eljily/Desktop/projects./projects/pacman/src/framework.c

CMakeFiles/pacman.dir/src/framework.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pacman.dir/src/framework.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eljily/Desktop/projects./projects/pacman/src/framework.c > CMakeFiles/pacman.dir/src/framework.c.i

CMakeFiles/pacman.dir/src/framework.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pacman.dir/src/framework.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eljily/Desktop/projects./projects/pacman/src/framework.c -o CMakeFiles/pacman.dir/src/framework.c.s

CMakeFiles/pacman.dir/src/firstLevel.c.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/firstLevel.c.o: /home/eljily/Desktop/projects./projects/pacman/src/firstLevel.c
CMakeFiles/pacman.dir/src/firstLevel.c.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/eljily/Desktop/projects./projects/pacman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/pacman.dir/src/firstLevel.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/firstLevel.c.o -MF CMakeFiles/pacman.dir/src/firstLevel.c.o.d -o CMakeFiles/pacman.dir/src/firstLevel.c.o -c /home/eljily/Desktop/projects./projects/pacman/src/firstLevel.c

CMakeFiles/pacman.dir/src/firstLevel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pacman.dir/src/firstLevel.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eljily/Desktop/projects./projects/pacman/src/firstLevel.c > CMakeFiles/pacman.dir/src/firstLevel.c.i

CMakeFiles/pacman.dir/src/firstLevel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pacman.dir/src/firstLevel.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eljily/Desktop/projects./projects/pacman/src/firstLevel.c -o CMakeFiles/pacman.dir/src/firstLevel.c.s

CMakeFiles/pacman.dir/src/fantomes.c.o: CMakeFiles/pacman.dir/flags.make
CMakeFiles/pacman.dir/src/fantomes.c.o: /home/eljily/Desktop/projects./projects/pacman/src/fantomes.c
CMakeFiles/pacman.dir/src/fantomes.c.o: CMakeFiles/pacman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/eljily/Desktop/projects./projects/pacman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/pacman.dir/src/fantomes.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pacman.dir/src/fantomes.c.o -MF CMakeFiles/pacman.dir/src/fantomes.c.o.d -o CMakeFiles/pacman.dir/src/fantomes.c.o -c /home/eljily/Desktop/projects./projects/pacman/src/fantomes.c

CMakeFiles/pacman.dir/src/fantomes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pacman.dir/src/fantomes.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/eljily/Desktop/projects./projects/pacman/src/fantomes.c > CMakeFiles/pacman.dir/src/fantomes.c.i

CMakeFiles/pacman.dir/src/fantomes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pacman.dir/src/fantomes.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/eljily/Desktop/projects./projects/pacman/src/fantomes.c -o CMakeFiles/pacman.dir/src/fantomes.c.s

# Object files for target pacman
pacman_OBJECTS = \
"CMakeFiles/pacman.dir/src/main.c.o" \
"CMakeFiles/pacman.dir/src/framework.c.o" \
"CMakeFiles/pacman.dir/src/firstLevel.c.o" \
"CMakeFiles/pacman.dir/src/fantomes.c.o"

# External object files for target pacman
pacman_EXTERNAL_OBJECTS =

pacman: CMakeFiles/pacman.dir/src/main.c.o
pacman: CMakeFiles/pacman.dir/src/framework.c.o
pacman: CMakeFiles/pacman.dir/src/firstLevel.c.o
pacman: CMakeFiles/pacman.dir/src/fantomes.c.o
pacman: CMakeFiles/pacman.dir/build.make
pacman: CMakeFiles/pacman.dir/compiler_depend.ts
pacman: /usr/lib/x86_64-linux-gnu/libSDL2.so
pacman: CMakeFiles/pacman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/eljily/Desktop/projects./projects/pacman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable pacman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pacman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pacman.dir/build: pacman
.PHONY : CMakeFiles/pacman.dir/build

CMakeFiles/pacman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pacman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pacman.dir/clean

CMakeFiles/pacman.dir/depend:
	cd /home/eljily/Desktop/projects./projects/pacman/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/eljily/Desktop/projects./projects/pacman /home/eljily/Desktop/projects./projects/pacman /home/eljily/Desktop/projects./projects/pacman/build /home/eljily/Desktop/projects./projects/pacman/build /home/eljily/Desktop/projects./projects/pacman/build/CMakeFiles/pacman.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pacman.dir/depend

