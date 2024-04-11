cmake_minimum_required(VERSION 3.10)
project(aspect)

# Include Directories
include_directories(
    Include
    Include/Internal
)

# Source Files
file(GLOB_RECURSE SOURCES "Aspect/*.c" "Grammar/*.c" "Include/*.c" "Include/Internal/*.c" "Lib/*.c" "Parser/*.c" "Programs/*.c" "Parser/Lexer/*.c")

# Output Directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin")

# Disable PDB
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /Z7")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Z7")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /Z7")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Z7")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})
