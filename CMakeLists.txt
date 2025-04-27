cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 17) #>14 for gtest
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(gtests VERSION 0.1.0 LANGUAGES C CXX)

#normal exe
include_directories(include)
add_executable(app src/main.cpp src/IObservable.cpp src/Input.cpp)

#download and build gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
FetchContent_MakeAvailable(googletest)

#testing
include(CTest)
enable_testing()

#need to build one executable, main fun is provided by google
add_executable(main_tests tests/main.cpp src/IObservable.cpp src/Input.cpp)

#in their lib
target_link_libraries(main_tests PRIVATE gtest_main)

#automatic test discovert those TEST...
include(GoogleTest)
gtest_discover_tests(main_tests)