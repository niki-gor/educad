# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nikita/SFML/educad_plain

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikita/SFML/educad_plain/build

# Include any dependencies generated for this target.
include entity2d/CMakeFiles/entity2d.dir/depend.make

# Include the progress variables for this target.
include entity2d/CMakeFiles/entity2d.dir/progress.make

# Include the compile flags for this target's objects.
include entity2d/CMakeFiles/entity2d.dir/flags.make

entity2d/CMakeFiles/entity2d.dir/entity2d.cpp.o: entity2d/CMakeFiles/entity2d.dir/flags.make
entity2d/CMakeFiles/entity2d.dir/entity2d.cpp.o: ../entity2d/entity2d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikita/SFML/educad_plain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object entity2d/CMakeFiles/entity2d.dir/entity2d.cpp.o"
	cd /home/nikita/SFML/educad_plain/build/entity2d && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/entity2d.dir/entity2d.cpp.o -c /home/nikita/SFML/educad_plain/entity2d/entity2d.cpp

entity2d/CMakeFiles/entity2d.dir/entity2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/entity2d.dir/entity2d.cpp.i"
	cd /home/nikita/SFML/educad_plain/build/entity2d && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikita/SFML/educad_plain/entity2d/entity2d.cpp > CMakeFiles/entity2d.dir/entity2d.cpp.i

entity2d/CMakeFiles/entity2d.dir/entity2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/entity2d.dir/entity2d.cpp.s"
	cd /home/nikita/SFML/educad_plain/build/entity2d && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikita/SFML/educad_plain/entity2d/entity2d.cpp -o CMakeFiles/entity2d.dir/entity2d.cpp.s

# Object files for target entity2d
entity2d_OBJECTS = \
"CMakeFiles/entity2d.dir/entity2d.cpp.o"

# External object files for target entity2d
entity2d_EXTERNAL_OBJECTS =

entity2d/libentity2d.a: entity2d/CMakeFiles/entity2d.dir/entity2d.cpp.o
entity2d/libentity2d.a: entity2d/CMakeFiles/entity2d.dir/build.make
entity2d/libentity2d.a: entity2d/CMakeFiles/entity2d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nikita/SFML/educad_plain/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libentity2d.a"
	cd /home/nikita/SFML/educad_plain/build/entity2d && $(CMAKE_COMMAND) -P CMakeFiles/entity2d.dir/cmake_clean_target.cmake
	cd /home/nikita/SFML/educad_plain/build/entity2d && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/entity2d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
entity2d/CMakeFiles/entity2d.dir/build: entity2d/libentity2d.a

.PHONY : entity2d/CMakeFiles/entity2d.dir/build

entity2d/CMakeFiles/entity2d.dir/clean:
	cd /home/nikita/SFML/educad_plain/build/entity2d && $(CMAKE_COMMAND) -P CMakeFiles/entity2d.dir/cmake_clean.cmake
.PHONY : entity2d/CMakeFiles/entity2d.dir/clean

entity2d/CMakeFiles/entity2d.dir/depend:
	cd /home/nikita/SFML/educad_plain/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikita/SFML/educad_plain /home/nikita/SFML/educad_plain/entity2d /home/nikita/SFML/educad_plain/build /home/nikita/SFML/educad_plain/build/entity2d /home/nikita/SFML/educad_plain/build/entity2d/CMakeFiles/entity2d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : entity2d/CMakeFiles/entity2d.dir/depend

