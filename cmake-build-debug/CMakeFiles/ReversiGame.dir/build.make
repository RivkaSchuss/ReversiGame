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
CMAKE_SOURCE_DIR = /Users/rivkaschuss/CLionProjects/ReversiGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ReversiGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ReversiGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReversiGame.dir/flags.make

CMakeFiles/ReversiGame.dir/main.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReversiGame.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/main.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/main.cpp

CMakeFiles/ReversiGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/main.cpp > CMakeFiles/ReversiGame.dir/main.cpp.i

CMakeFiles/ReversiGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/main.cpp -o CMakeFiles/ReversiGame.dir/main.cpp.s

CMakeFiles/ReversiGame.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/main.cpp.o.requires

CMakeFiles/ReversiGame.dir/main.cpp.o.provides: CMakeFiles/ReversiGame.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/main.cpp.o.provides

CMakeFiles/ReversiGame.dir/main.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/main.cpp.o


CMakeFiles/ReversiGame.dir/Board.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/Board.cpp.o: ../Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ReversiGame.dir/Board.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/Board.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/Board.cpp

CMakeFiles/ReversiGame.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/Board.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/Board.cpp > CMakeFiles/ReversiGame.dir/Board.cpp.i

CMakeFiles/ReversiGame.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/Board.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/Board.cpp -o CMakeFiles/ReversiGame.dir/Board.cpp.s

CMakeFiles/ReversiGame.dir/Board.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/Board.cpp.o.requires

CMakeFiles/ReversiGame.dir/Board.cpp.o.provides: CMakeFiles/ReversiGame.dir/Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/Board.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/Board.cpp.o.provides

CMakeFiles/ReversiGame.dir/Board.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/Board.cpp.o


CMakeFiles/ReversiGame.dir/Location.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/Location.cpp.o: ../Location.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ReversiGame.dir/Location.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/Location.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/Location.cpp

CMakeFiles/ReversiGame.dir/Location.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/Location.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/Location.cpp > CMakeFiles/ReversiGame.dir/Location.cpp.i

CMakeFiles/ReversiGame.dir/Location.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/Location.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/Location.cpp -o CMakeFiles/ReversiGame.dir/Location.cpp.s

CMakeFiles/ReversiGame.dir/Location.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/Location.cpp.o.requires

CMakeFiles/ReversiGame.dir/Location.cpp.o.provides: CMakeFiles/ReversiGame.dir/Location.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/Location.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/Location.cpp.o.provides

CMakeFiles/ReversiGame.dir/Location.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/Location.cpp.o


CMakeFiles/ReversiGame.dir/Cell.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/Cell.cpp.o: ../Cell.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ReversiGame.dir/Cell.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/Cell.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/Cell.cpp

CMakeFiles/ReversiGame.dir/Cell.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/Cell.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/Cell.cpp > CMakeFiles/ReversiGame.dir/Cell.cpp.i

CMakeFiles/ReversiGame.dir/Cell.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/Cell.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/Cell.cpp -o CMakeFiles/ReversiGame.dir/Cell.cpp.s

CMakeFiles/ReversiGame.dir/Cell.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/Cell.cpp.o.requires

CMakeFiles/ReversiGame.dir/Cell.cpp.o.provides: CMakeFiles/ReversiGame.dir/Cell.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/Cell.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/Cell.cpp.o.provides

CMakeFiles/ReversiGame.dir/Cell.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/Cell.cpp.o


CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o: ../AbstractPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/AbstractPlayer.cpp

CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/AbstractPlayer.cpp > CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.i

CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/AbstractPlayer.cpp -o CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.s

CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o.requires

CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o.provides: CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o.provides

CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o


CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o: ../ConsolePlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/ConsolePlayer.cpp

CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/ConsolePlayer.cpp > CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.i

CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/ConsolePlayer.cpp -o CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.s

CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o.requires

CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o.provides: CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o.provides

CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o


CMakeFiles/ReversiGame.dir/Game.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ReversiGame.dir/Game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/Game.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/Game.cpp

CMakeFiles/ReversiGame.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/Game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/Game.cpp > CMakeFiles/ReversiGame.dir/Game.cpp.i

CMakeFiles/ReversiGame.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/Game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/Game.cpp -o CMakeFiles/ReversiGame.dir/Game.cpp.s

CMakeFiles/ReversiGame.dir/Game.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/Game.cpp.o.requires

CMakeFiles/ReversiGame.dir/Game.cpp.o.provides: CMakeFiles/ReversiGame.dir/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/Game.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/Game.cpp.o.provides

CMakeFiles/ReversiGame.dir/Game.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/Game.cpp.o


CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o: ../AbstractGameLogic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/AbstractGameLogic.cpp

CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/AbstractGameLogic.cpp > CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.i

CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/AbstractGameLogic.cpp -o CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.s

CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o.requires

CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o.provides: CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o.provides

CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o


CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o: CMakeFiles/ReversiGame.dir/flags.make
CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o: ../DefaultGameLogic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o -c /Users/rivkaschuss/CLionProjects/ReversiGame/DefaultGameLogic.cpp

CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rivkaschuss/CLionProjects/ReversiGame/DefaultGameLogic.cpp > CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.i

CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rivkaschuss/CLionProjects/ReversiGame/DefaultGameLogic.cpp -o CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.s

CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o.requires:

.PHONY : CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o.requires

CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o.provides: CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReversiGame.dir/build.make CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o.provides.build
.PHONY : CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o.provides

CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o.provides.build: CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o


# Object files for target ReversiGame
ReversiGame_OBJECTS = \
"CMakeFiles/ReversiGame.dir/main.cpp.o" \
"CMakeFiles/ReversiGame.dir/Board.cpp.o" \
"CMakeFiles/ReversiGame.dir/Location.cpp.o" \
"CMakeFiles/ReversiGame.dir/Cell.cpp.o" \
"CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o" \
"CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o" \
"CMakeFiles/ReversiGame.dir/Game.cpp.o" \
"CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o" \
"CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o"

# External object files for target ReversiGame
ReversiGame_EXTERNAL_OBJECTS =

ReversiGame: CMakeFiles/ReversiGame.dir/main.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/Board.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/Location.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/Cell.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/Game.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o
ReversiGame: CMakeFiles/ReversiGame.dir/build.make
ReversiGame: CMakeFiles/ReversiGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ReversiGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReversiGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReversiGame.dir/build: ReversiGame

.PHONY : CMakeFiles/ReversiGame.dir/build

CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/main.cpp.o.requires
CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/Board.cpp.o.requires
CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/Location.cpp.o.requires
CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/Cell.cpp.o.requires
CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/AbstractPlayer.cpp.o.requires
CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/ConsolePlayer.cpp.o.requires
CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/Game.cpp.o.requires
CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/AbstractGameLogic.cpp.o.requires
CMakeFiles/ReversiGame.dir/requires: CMakeFiles/ReversiGame.dir/DefaultGameLogic.cpp.o.requires

.PHONY : CMakeFiles/ReversiGame.dir/requires

CMakeFiles/ReversiGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReversiGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReversiGame.dir/clean

CMakeFiles/ReversiGame.dir/depend:
	cd /Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rivkaschuss/CLionProjects/ReversiGame /Users/rivkaschuss/CLionProjects/ReversiGame /Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug /Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug /Users/rivkaschuss/CLionProjects/ReversiGame/cmake-build-debug/CMakeFiles/ReversiGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReversiGame.dir/depend

