cmake_minimum_required(VERSION 3.17)
project(clib)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/703bd9caab50b139428cea1aaff9974ebee5742e.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(clib
        main.cpp
        src/core/bstree.c
        src/core/bstree.h
        src/core/fibonacci.c
        src/core/fibonacci.h
        src/core/rbtree.c
        src/core/rbtree.h
        src/core/linkedlist.c src/core/linkedlist.h src/core/stack.c src/core/stack.h src/core/queue.c src/core/queue.h)

enable_testing()
add_executable(
        clib_test
        test.cpp
        src/core/fibonacci.c
        src/core/fibonacci.h
        src/core/bstree.c
        src/core/bstree.h
        src/core/linkedlist.c src/core/linkedlist.h src/core/stack.c src/core/stack.h src/core/queue.c src/core/queue.h)
target_link_libraries(
        clib_test
        gtest_main
)
include(GoogleTest)
gtest_discover_tests(clib_test)