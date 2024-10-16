# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the C standard and compiler flags
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -Wpedantic")

# Define the output directory for binaries
set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")

# Create the output directory if it doesn't exist
file(MAKE_DIRECTORY ${OUTPUT_DIR})

# List of source files
set(SOURCES
    MemCast.c
    MatrixMult.c
    Array2D.c
)

# Loop through each source file and add executable targets
foreach(SRC ${SOURCES})
    get_filename_component(TARGET ${SRC} NAME_WE) # Extract the file name without extension
    add_executable(${TARGET} ${SRC})
    set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
endforeach()

# Add a clean target to remove the output directory
add_custom_target(CLEAN
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${OUTPUT_DIR}
    COMMENT "Cleaning up the output directory."
)
