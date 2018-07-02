# set minimum cmake version
cmake_minimum_required (VERSION 2.6)

# set project name
project (Tutorial)

# The version number.
set (Tutorial_VERSION_MAJOR 2)
set (Tutorial_VERSION_MINOR 0)

 
# add the binary tree so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

# should we use our own math functions? // comment next line and see
option (USE_MYMATH  "Use tutorial provided math implementation" ON) 

include_directories ("/usr/local/bin")
include_directories ("/usr/local/include")
add_library(MathFunctions STATIC IMPORTED)
set_target_properties(MathFunctions PROPERTIES IMPORTED_LOCATION /usr/local/bin/libMathFunctions.a)

# add the executable
add_executable(Tutorial tutorial.cpp)

# link libraries to produce app
target_link_libraries (Tutorial MathFunctions)
