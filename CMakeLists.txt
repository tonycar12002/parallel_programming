cmake_minimum_required (VERSION 2.8.11)
project (parallel_programming)

find_package(OpenCV 3.3.1 REQUIRED)
find_package(Eigen3)
find_package(OpenMP REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${CMAKE_INSTALL_PREFIX}/include
  ${OpenCV_INCLUDE_DIRS}
)

add_subdirectory(src/openmp)