# first we add the executable that generates the table
add_executable(MakeTable MakeTable.cpp)

# add the command to generate the source code
add_custom_command (
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
	DEPENDS MakeTable
	# $ MakeTable "Table.h"  // create table
	COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)

# add the binary tree directory to the search path for include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )
 
# add the main library
add_library(MathFunctions MakeTable.cpp mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

# install app into system DESTINATION = /usr/local
install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h mysqrt.h DESTINATION include)

