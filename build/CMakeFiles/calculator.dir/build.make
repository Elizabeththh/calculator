# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elizabeththh/code/cpp/calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elizabeththh/code/cpp/calculator/build

# Include any dependencies generated for this target.
include CMakeFiles/calculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/calculator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calculator.dir/flags.make

CMakeFiles/calculator.dir/src/addition.cpp.o: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/src/addition.cpp.o: /home/elizabeththh/code/cpp/calculator/src/addition.cpp
CMakeFiles/calculator.dir/src/addition.cpp.o: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elizabeththh/code/cpp/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calculator.dir/src/addition.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/src/addition.cpp.o -MF CMakeFiles/calculator.dir/src/addition.cpp.o.d -o CMakeFiles/calculator.dir/src/addition.cpp.o -c /home/elizabeththh/code/cpp/calculator/src/addition.cpp

CMakeFiles/calculator.dir/src/addition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/src/addition.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elizabeththh/code/cpp/calculator/src/addition.cpp > CMakeFiles/calculator.dir/src/addition.cpp.i

CMakeFiles/calculator.dir/src/addition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/src/addition.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elizabeththh/code/cpp/calculator/src/addition.cpp -o CMakeFiles/calculator.dir/src/addition.cpp.s

CMakeFiles/calculator.dir/src/calculation.cpp.o: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/src/calculation.cpp.o: /home/elizabeththh/code/cpp/calculator/src/calculation.cpp
CMakeFiles/calculator.dir/src/calculation.cpp.o: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elizabeththh/code/cpp/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/calculator.dir/src/calculation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/src/calculation.cpp.o -MF CMakeFiles/calculator.dir/src/calculation.cpp.o.d -o CMakeFiles/calculator.dir/src/calculation.cpp.o -c /home/elizabeththh/code/cpp/calculator/src/calculation.cpp

CMakeFiles/calculator.dir/src/calculation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/src/calculation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elizabeththh/code/cpp/calculator/src/calculation.cpp > CMakeFiles/calculator.dir/src/calculation.cpp.i

CMakeFiles/calculator.dir/src/calculation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/src/calculation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elizabeththh/code/cpp/calculator/src/calculation.cpp -o CMakeFiles/calculator.dir/src/calculation.cpp.s

CMakeFiles/calculator.dir/src/calculator.cpp.o: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/src/calculator.cpp.o: /home/elizabeththh/code/cpp/calculator/src/calculator.cpp
CMakeFiles/calculator.dir/src/calculator.cpp.o: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elizabeththh/code/cpp/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/calculator.dir/src/calculator.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/src/calculator.cpp.o -MF CMakeFiles/calculator.dir/src/calculator.cpp.o.d -o CMakeFiles/calculator.dir/src/calculator.cpp.o -c /home/elizabeththh/code/cpp/calculator/src/calculator.cpp

CMakeFiles/calculator.dir/src/calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/src/calculator.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elizabeththh/code/cpp/calculator/src/calculator.cpp > CMakeFiles/calculator.dir/src/calculator.cpp.i

CMakeFiles/calculator.dir/src/calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/src/calculator.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elizabeththh/code/cpp/calculator/src/calculator.cpp -o CMakeFiles/calculator.dir/src/calculator.cpp.s

CMakeFiles/calculator.dir/src/division.cpp.o: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/src/division.cpp.o: /home/elizabeththh/code/cpp/calculator/src/division.cpp
CMakeFiles/calculator.dir/src/division.cpp.o: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elizabeththh/code/cpp/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/calculator.dir/src/division.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/src/division.cpp.o -MF CMakeFiles/calculator.dir/src/division.cpp.o.d -o CMakeFiles/calculator.dir/src/division.cpp.o -c /home/elizabeththh/code/cpp/calculator/src/division.cpp

CMakeFiles/calculator.dir/src/division.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/src/division.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elizabeththh/code/cpp/calculator/src/division.cpp > CMakeFiles/calculator.dir/src/division.cpp.i

CMakeFiles/calculator.dir/src/division.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/src/division.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elizabeththh/code/cpp/calculator/src/division.cpp -o CMakeFiles/calculator.dir/src/division.cpp.s

CMakeFiles/calculator.dir/src/main.cpp.o: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/src/main.cpp.o: /home/elizabeththh/code/cpp/calculator/src/main.cpp
CMakeFiles/calculator.dir/src/main.cpp.o: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elizabeththh/code/cpp/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/calculator.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/src/main.cpp.o -MF CMakeFiles/calculator.dir/src/main.cpp.o.d -o CMakeFiles/calculator.dir/src/main.cpp.o -c /home/elizabeththh/code/cpp/calculator/src/main.cpp

CMakeFiles/calculator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elizabeththh/code/cpp/calculator/src/main.cpp > CMakeFiles/calculator.dir/src/main.cpp.i

CMakeFiles/calculator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elizabeththh/code/cpp/calculator/src/main.cpp -o CMakeFiles/calculator.dir/src/main.cpp.s

CMakeFiles/calculator.dir/src/multiplication.cpp.o: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/src/multiplication.cpp.o: /home/elizabeththh/code/cpp/calculator/src/multiplication.cpp
CMakeFiles/calculator.dir/src/multiplication.cpp.o: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elizabeththh/code/cpp/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/calculator.dir/src/multiplication.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/src/multiplication.cpp.o -MF CMakeFiles/calculator.dir/src/multiplication.cpp.o.d -o CMakeFiles/calculator.dir/src/multiplication.cpp.o -c /home/elizabeththh/code/cpp/calculator/src/multiplication.cpp

CMakeFiles/calculator.dir/src/multiplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/src/multiplication.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elizabeththh/code/cpp/calculator/src/multiplication.cpp > CMakeFiles/calculator.dir/src/multiplication.cpp.i

CMakeFiles/calculator.dir/src/multiplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/src/multiplication.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elizabeththh/code/cpp/calculator/src/multiplication.cpp -o CMakeFiles/calculator.dir/src/multiplication.cpp.s

CMakeFiles/calculator.dir/src/subtraction.cpp.o: CMakeFiles/calculator.dir/flags.make
CMakeFiles/calculator.dir/src/subtraction.cpp.o: /home/elizabeththh/code/cpp/calculator/src/subtraction.cpp
CMakeFiles/calculator.dir/src/subtraction.cpp.o: CMakeFiles/calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elizabeththh/code/cpp/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/calculator.dir/src/subtraction.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator.dir/src/subtraction.cpp.o -MF CMakeFiles/calculator.dir/src/subtraction.cpp.o.d -o CMakeFiles/calculator.dir/src/subtraction.cpp.o -c /home/elizabeththh/code/cpp/calculator/src/subtraction.cpp

CMakeFiles/calculator.dir/src/subtraction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator.dir/src/subtraction.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elizabeththh/code/cpp/calculator/src/subtraction.cpp > CMakeFiles/calculator.dir/src/subtraction.cpp.i

CMakeFiles/calculator.dir/src/subtraction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator.dir/src/subtraction.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elizabeththh/code/cpp/calculator/src/subtraction.cpp -o CMakeFiles/calculator.dir/src/subtraction.cpp.s

# Object files for target calculator
calculator_OBJECTS = \
"CMakeFiles/calculator.dir/src/addition.cpp.o" \
"CMakeFiles/calculator.dir/src/calculation.cpp.o" \
"CMakeFiles/calculator.dir/src/calculator.cpp.o" \
"CMakeFiles/calculator.dir/src/division.cpp.o" \
"CMakeFiles/calculator.dir/src/main.cpp.o" \
"CMakeFiles/calculator.dir/src/multiplication.cpp.o" \
"CMakeFiles/calculator.dir/src/subtraction.cpp.o"

# External object files for target calculator
calculator_EXTERNAL_OBJECTS =

calculator: CMakeFiles/calculator.dir/src/addition.cpp.o
calculator: CMakeFiles/calculator.dir/src/calculation.cpp.o
calculator: CMakeFiles/calculator.dir/src/calculator.cpp.o
calculator: CMakeFiles/calculator.dir/src/division.cpp.o
calculator: CMakeFiles/calculator.dir/src/main.cpp.o
calculator: CMakeFiles/calculator.dir/src/multiplication.cpp.o
calculator: CMakeFiles/calculator.dir/src/subtraction.cpp.o
calculator: CMakeFiles/calculator.dir/build.make
calculator: CMakeFiles/calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/elizabeththh/code/cpp/calculator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calculator.dir/build: calculator
.PHONY : CMakeFiles/calculator.dir/build

CMakeFiles/calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calculator.dir/clean

CMakeFiles/calculator.dir/depend:
	cd /home/elizabeththh/code/cpp/calculator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elizabeththh/code/cpp/calculator /home/elizabeththh/code/cpp/calculator /home/elizabeththh/code/cpp/calculator/build /home/elizabeththh/code/cpp/calculator/build /home/elizabeththh/code/cpp/calculator/build/CMakeFiles/calculator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/calculator.dir/depend

