cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(FirstBoost)

find_package(CUDAToolkit REQUIRED)
find_package(Boost 1.85.0 REQUIRED COMPONENTS regex)

# google test added using instructions here https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

include_directories(${Boost_INCLUDE_DIRS})
add_subdirectory(CudaHelpers_lib)
add_executable(FirstBoost example.cpp)
target_link_libraries(FirstBoost CudaHelpers_lib Boost::regex CUDA::cudart)
target_include_directories(FirstBoost PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/CudaHelpers_lib"
                           )
enable_testing()
add_executable(
    example_test
    example_test.cpp
)
target_link_libraries(
    example_test
    GTest::gtest_main
    CudaHelpers_lib
)
include(GoogleTest)
gtest_discover_tests(example_test)

