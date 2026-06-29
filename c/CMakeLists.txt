cmake_minimum_required(VERSION 3.14)
project(ci_raspberry_python_c C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# --- Hauptprogramm ---
add_executable(hello_world
    src/main.c
    src/greeting.c
)
target_include_directories(hello_world PRIVATE src)

# --- Unity Test Framework via FetchContent ---
include(FetchContent)
FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.6.0
)
FetchContent_MakeAvailable(unity)

enable_testing()

add_executable(test_main
    test/test_main.c
    src/greeting.c
)
target_include_directories(test_main PRIVATE src)
target_link_libraries(test_main PRIVATE unity)

add_test(NAME greeting_test COMMAND test_main)