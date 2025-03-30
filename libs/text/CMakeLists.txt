#
# Define library source files
#

set(LIB_SOURCES
    buffer.cpp
    ops.cpp
)

#
# Create a library called GameLib
#

add_library(lib_text ${LIB_SOURCES})

#
# Include headers
#

target_include_directories(lib_text PUBLIC ${CMAKE_SOURCE_DIR}/include)

#
# visit subdir for testing for the library
#

add_subdirectory(tests)
