cmake_minimum_required(VERSION 3.20)

# Project name and version
project(wed VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)




find_package(Curses REQUIRED)



# Set output directory for binaries
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ============================
# Add Libraries
# ============================
add_subdirectory(libs/text)


# ============================
# Build Main Executable
# ============================
# Define source files
set(SRC_FILES
    src/main.cpp
)

# Create the main executable
add_executable(wed ${SRC_FILES})

# Include headers and link the libraries
target_include_directories(wed PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
target_include_directories(wed PRIVATE ${CMAKE_SOURCE_DIR}/libs/text/include)
target_include_directories(wed PRIVATE ${CURSES_INCLUDE_DIR})

target_link_libraries(wed PRIVATE lib_text)
target_link_libraries(wed PRIVATE ${CURSES_LIBRARIES})

# ============================
# Enable CTest for Testing
# ============================






enable_testing()
