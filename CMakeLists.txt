cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(FirstBoost)

find_package(CUDAToolkit REQUIRED)

find_package(Boost 1.85.0 REQUIRED COMPONENTS regex)

include_directories(${Boost_INCLUDE_DIRS})
add_subdirectory(CudaHelpers_lib)
add_executable(FirstBoost example.cpp)
target_link_libraries(FirstBoost CudaHelpers_lib Boost::regex CUDA::cudart)
target_include_directories(FirstBoost PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/CudaHelpers_lib"
                           )


