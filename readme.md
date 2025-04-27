# Gtests sample
This project demonstates how to use google test with cmake.
The gtest dependency is pulled from github and build inside cmake.

## Description
- src include -> contain code that needs testing
- tests -> contains tests
- tests\main.cpp\MouseTests.Move -> example passed tests
- tests\main.cpp\MouseTests.Move2 -> example failed tests

## How to run
1. Open in vscode
2. Edit presets to match your compiler
3. Go to CMake tab
4. Configure and build
5. Run tests.
6. Observe output in console.

## Automatic download
CMakeLists.txt
```
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
FetchContent_MakeAvailable(googletest
```