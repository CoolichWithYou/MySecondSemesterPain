# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = C:\Users\Test-notebook\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7142.21\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Test-notebook\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7142.21\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Test-notebook\Desktop\opi-dz

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug

# Include any dependencies generated for this target.
include App/CMakeFiles/App.dir/depend.make

# Include the progress variables for this target.
include App/CMakeFiles/App.dir/progress.make

# Include the compile flags for this target's objects.
include App/CMakeFiles/App.dir/flags.make

App/CMakeFiles/App.dir/app.cpp.obj: App/CMakeFiles/App.dir/flags.make
App/CMakeFiles/App.dir/app.cpp.obj: App/CMakeFiles/App.dir/includes_CXX.rsp
App/CMakeFiles/App.dir/app.cpp.obj: ../App/app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object App/CMakeFiles/App.dir/app.cpp.obj"
	cd /d C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\App && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\App.dir\app.cpp.obj -c C:\Users\Test-notebook\Desktop\opi-dz\App\app.cpp

App/CMakeFiles/App.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/App.dir/app.cpp.i"
	cd /d C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\App && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Test-notebook\Desktop\opi-dz\App\app.cpp > CMakeFiles\App.dir\app.cpp.i

App/CMakeFiles/App.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/App.dir/app.cpp.s"
	cd /d C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\App && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Test-notebook\Desktop\opi-dz\App\app.cpp -o CMakeFiles\App.dir\app.cpp.s

# Object files for target App
App_OBJECTS = \
"CMakeFiles/App.dir/app.cpp.obj"

# External object files for target App
App_EXTERNAL_OBJECTS =

App/libApp.a: App/CMakeFiles/App.dir/app.cpp.obj
App/libApp.a: App/CMakeFiles/App.dir/build.make
App/libApp.a: App/CMakeFiles/App.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libApp.a"
	cd /d C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\App && $(CMAKE_COMMAND) -P CMakeFiles\App.dir\cmake_clean_target.cmake
	cd /d C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\App && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\App.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
App/CMakeFiles/App.dir/build: App/libApp.a

.PHONY : App/CMakeFiles/App.dir/build

App/CMakeFiles/App.dir/clean:
	cd /d C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\App && $(CMAKE_COMMAND) -P CMakeFiles\App.dir\cmake_clean.cmake
.PHONY : App/CMakeFiles/App.dir/clean

App/CMakeFiles/App.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Test-notebook\Desktop\opi-dz C:\Users\Test-notebook\Desktop\opi-dz\App C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\App C:\Users\Test-notebook\Desktop\opi-dz\cmake-build-debug\App\CMakeFiles\App.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : App/CMakeFiles/App.dir/depend
