# set minimum cmake version
cmake_minimum_required (VERSION 2.6)

# set project name
project (Tutorial)

# The version number.
set (Tutorial_VERSION_MAJOR 2)
set (Tutorial_VERSION_MINOR 0)
 
# configure a header file to pass some of the CMake settings
configure_file (
	"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
	"${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

 
# add the binary tree so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

# should we use our own math functions? // comment next line and see
option (USE_MYMATH  "Use tutorial provided math implementation" ON) 

# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)
        

# add the executable
add_executable(Tutorial tutorial.cpp)

# link libraries to produce app
target_link_libraries (Tutorial ${EXTRA_LIBS})
