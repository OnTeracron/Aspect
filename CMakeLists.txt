cmake_minimum_required(VERSION 3.10)
project(aspect)

# Include Directories
include_directories(
    Include
    Include/Internal
)

# Source Files
file(GLOB_RECURSE SOURCES "Aspect/*.c" "Grammar/*.c" "Include/*.c" "Include/Internal/*.c" "Lib/*.c" "Parser/*.c" "Programs/*.c" "Parser/Lexer/*.c")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)