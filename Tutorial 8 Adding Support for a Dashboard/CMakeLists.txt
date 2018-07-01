# to support for submitting our test results to a dashboard
# just have to run those tests and submit them to a dashboard. 
# To include support for dashboards we include the CTest module 


# set minimum cmake version
cmake_minimum_required (VERSION 2.6)

# set project name
project (Tutorial)

# The version number.
set (Tutorial_VERSION_MAJOR 2)
set (Tutorial_VERSION_MINOR 0)
 
# should we use our own math functions? // comment next line and see
option (USE_MYMATH  "Use tutorial provided math implementation" ON) 

# does this system provide the log and exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG) # define HAVE_LOG if log exist
check_function_exists (exp HAVE_EXP) # define HAVE_EXP if exp exist


# configure a header file to pass some of the CMake settings
configure_file (
	"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
	"${PROJECT_BINARY_DIR}/TutorialConfig.h"
)
 
# add the binary tree so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

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

# ------|||------------||Unit Testing||------------|||------
# calls: $ ctest CTestTestfile.cmake

# add the install targets
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# enable testing
enable_testing ()

# does the application run
add_test (TutorialRuns Tutorial 25)

# does the usage message work?
add_test (TutorialUsage Tutorial)
set_tests_properties (TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number" )
  
# If you wanted to add a lot of tests to test different input values you might consider creating a macro like the following:
#define a macro to simplify adding tests, then use it
macro (test_this arg result)
	add_test (TutorialComp${arg} Tutorial ${arg})
	set_tests_properties (TutorialComp${arg}
	PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (test_this)
 
# do a bunch of result based tests
test_this ( 4   	"4 is 2"	)
test_this (100 	"100 is 10"		)


# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set (CPACK_PACKAGE_CONTACT       "foo@bar.org")
include (CPack)

# enable dashboard scripting
include (CTest)

# submit tests to a dashboard
set (CTEST_PROJECT_NAME "Tutorial")

