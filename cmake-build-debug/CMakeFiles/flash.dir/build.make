# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3/cmake-build-debug

# Utility rule file for flash.

# Include the progress variables for this target.
include CMakeFiles/flash.dir/progress.make

CMakeFiles/flash: hw3.obj
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "dump program to the robot on port /dev/ttyACM0"
	AVR_OBJCOPY-NOTFOUND -R .eeprom -O ihex hw3.obj hw3.hex
	AVR_DUDE-NOTFOUND -p m328p -c avrisp2 -P /dev/ttyACM0 -U flash:w:hw3.hex

flash: CMakeFiles/flash
flash: CMakeFiles/flash.dir/build.make

.PHONY : flash

# Rule to build all files generated by this target.
CMakeFiles/flash.dir/build: flash

.PHONY : CMakeFiles/flash.dir/build

CMakeFiles/flash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flash.dir/clean

CMakeFiles/flash.dir/depend:
	cd /Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3 /Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3 /Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3/cmake-build-debug /Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3/cmake-build-debug /Users/Kyle_hall/username=khall5/fall17/GroupA36/hw3/cmake-build-debug/CMakeFiles/flash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flash.dir/depend

