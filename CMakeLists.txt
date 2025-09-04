cmake_minimum_required(VERSION 3.15)

project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt5 REQUIRED Widgets)

# Подключение Catch2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(calculator
    src/main.cpp
    src/calculator.cpp
)

target_link_libraries(calculator Qt5::Widgets)

# Тесты
enable_testing()

add_executable(test_calculator
    tests/test_calculator.cpp
    src/calculator.cpp
)

target_link_libraries(test_calculator PRIVATE Catch2::Catch2WithMain)
include(CTest)
include(Catch)
catch_discover_tests(test_calculator)
