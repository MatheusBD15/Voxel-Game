# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\MatheusBD\Desktop\minecraftClone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug

# Include any dependencies generated for this target.
include vendors/glad/CMakeFiles/glad.dir/depend.make
# Include the progress variables for this target.
include vendors/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include vendors/glad/CMakeFiles/glad.dir/flags.make

vendors/glad/CMakeFiles/glad.dir/src/glad.c.obj: vendors/glad/CMakeFiles/glad.dir/flags.make
vendors/glad/CMakeFiles/glad.dir/src/glad.c.obj: vendors/glad/CMakeFiles/glad.dir/includes_C.rsp
vendors/glad/CMakeFiles/glad.dir/src/glad.c.obj: ../vendors/glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object vendors/glad/CMakeFiles/glad.dir/src/glad.c.obj"
	cd /d C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\vendors\glad && E:\Builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\glad.dir\src\glad.c.obj -c C:\Users\MatheusBD\Desktop\minecraftClone\vendors\glad\src\glad.c

vendors/glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd /d C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\vendors\glad && E:\Builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\MatheusBD\Desktop\minecraftClone\vendors\glad\src\glad.c > CMakeFiles\glad.dir\src\glad.c.i

vendors/glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd /d C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\vendors\glad && E:\Builds\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\MatheusBD\Desktop\minecraftClone\vendors\glad\src\glad.c -o CMakeFiles\glad.dir\src\glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.obj"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

vendors/glad/libglad.a: vendors/glad/CMakeFiles/glad.dir/src/glad.c.obj
vendors/glad/libglad.a: vendors/glad/CMakeFiles/glad.dir/build.make
vendors/glad/libglad.a: vendors/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglad.a"
	cd /d C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\vendors\glad && $(CMAKE_COMMAND) -P CMakeFiles\glad.dir\cmake_clean_target.cmake
	cd /d C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\vendors\glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\glad.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vendors/glad/CMakeFiles/glad.dir/build: vendors/glad/libglad.a
.PHONY : vendors/glad/CMakeFiles/glad.dir/build

vendors/glad/CMakeFiles/glad.dir/clean:
	cd /d C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\vendors\glad && $(CMAKE_COMMAND) -P CMakeFiles\glad.dir\cmake_clean.cmake
.PHONY : vendors/glad/CMakeFiles/glad.dir/clean

vendors/glad/CMakeFiles/glad.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\MatheusBD\Desktop\minecraftClone C:\Users\MatheusBD\Desktop\minecraftClone\vendors\glad C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\vendors\glad C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\vendors\glad\CMakeFiles\glad.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : vendors/glad/CMakeFiles/glad.dir/depend

