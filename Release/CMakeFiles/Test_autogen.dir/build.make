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
CMAKE_SOURCE_DIR = "/home/cc/Desktop/Git_Project/Dev2022 _V1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/cc/Desktop/Git_Project/Dev2022 _V1/Release"

# Utility rule file for Test_autogen.

# Include the progress variables for this target.
include CMakeFiles/Test_autogen.dir/progress.make

CMakeFiles/Test_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/cc/Desktop/Git_Project/Dev2022 _V1/Release/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Test"
	/usr/bin/cmake -E cmake_autogen "/home/cc/Desktop/Git_Project/Dev2022 _V1/Release/CMakeFiles/Test_autogen.dir/AutogenInfo.json" Release

Test_autogen: CMakeFiles/Test_autogen
Test_autogen: CMakeFiles/Test_autogen.dir/build.make

.PHONY : Test_autogen

# Rule to build all files generated by this target.
CMakeFiles/Test_autogen.dir/build: Test_autogen

.PHONY : CMakeFiles/Test_autogen.dir/build

CMakeFiles/Test_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test_autogen.dir/clean

CMakeFiles/Test_autogen.dir/depend:
	cd "/home/cc/Desktop/Git_Project/Dev2022 _V1/Release" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/cc/Desktop/Git_Project/Dev2022 _V1" "/home/cc/Desktop/Git_Project/Dev2022 _V1" "/home/cc/Desktop/Git_Project/Dev2022 _V1/Release" "/home/cc/Desktop/Git_Project/Dev2022 _V1/Release" "/home/cc/Desktop/Git_Project/Dev2022 _V1/Release/CMakeFiles/Test_autogen.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Test_autogen.dir/depend

