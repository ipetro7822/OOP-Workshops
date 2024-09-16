cmake_minimum_required(VERSION 3.0.0)
project(w1p2 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB PROJ_SRC "*.h" "*.cpp")
add_executable(ws ${PROJ_SRC})


# Set the output directory for the executable to the parent directory of the build directory
set_target_properties(w2p1 PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})


# Globbing .csv files
file(GLOB CSV_FILES "*.txt")

# Iterating over each .csv file and copying it to the binary directory
foreach(CSV_FILE ${CSV_FILES})
  get_filename_component(CSV_FILENAME ${CSV_FILE} NAME)
  configure_file(${CSV_FILE} ${CMAKE_BINARY_DIR}/${CSV_FILENAME} COPYONLY)
endforeach()


include(CPack)
