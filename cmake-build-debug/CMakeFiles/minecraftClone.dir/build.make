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
include CMakeFiles/minecraftClone.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/minecraftClone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minecraftClone.dir/flags.make

CMakeFiles/minecraftClone.dir/main.cpp.obj: CMakeFiles/minecraftClone.dir/flags.make
CMakeFiles/minecraftClone.dir/main.cpp.obj: CMakeFiles/minecraftClone.dir/includes_CXX.rsp
CMakeFiles/minecraftClone.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minecraftClone.dir/main.cpp.obj"
	E:\Builds\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\minecraftClone.dir\main.cpp.obj -c C:\Users\MatheusBD\Desktop\minecraftClone\main.cpp

CMakeFiles/minecraftClone.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minecraftClone.dir/main.cpp.i"
	E:\Builds\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\MatheusBD\Desktop\minecraftClone\main.cpp > CMakeFiles\minecraftClone.dir\main.cpp.i

CMakeFiles/minecraftClone.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minecraftClone.dir/main.cpp.s"
	E:\Builds\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\MatheusBD\Desktop\minecraftClone\main.cpp -o CMakeFiles\minecraftClone.dir\main.cpp.s

# Object files for target minecraftClone
minecraftClone_OBJECTS = \
"CMakeFiles/minecraftClone.dir/main.cpp.obj"

# External object files for target minecraftClone
minecraftClone_EXTERNAL_OBJECTS =

minecraftClone.exe: CMakeFiles/minecraftClone.dir/main.cpp.obj
minecraftClone.exe: CMakeFiles/minecraftClone.dir/build.make
minecraftClone.exe: CMakeFiles/minecraftClone.dir/linklibs.rsp
minecraftClone.exe: CMakeFiles/minecraftClone.dir/objects1.rsp
minecraftClone.exe: CMakeFiles/minecraftClone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable minecraftClone.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\minecraftClone.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minecraftClone.dir/build: minecraftClone.exe
.PHONY : CMakeFiles/minecraftClone.dir/build

CMakeFiles/minecraftClone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\minecraftClone.dir\cmake_clean.cmake
.PHONY : CMakeFiles/minecraftClone.dir/clean

CMakeFiles/minecraftClone.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\MatheusBD\Desktop\minecraftClone C:\Users\MatheusBD\Desktop\minecraftClone C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug C:\Users\MatheusBD\Desktop\minecraftClone\cmake-build-debug\CMakeFiles\minecraftClone.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minecraftClone.dir/depend

