cmake_minimum_required(VERSION 3.17)

project(engine_tests)
enable_testing()

set(BOOST_INCLUDE_DIRS $boost_installation_prefix/include)

add_executable(engine_tests
    allocator_tests.cpp
)

target_include_directories(engine_tests PRIVATE ${BOOST_INCLUDE_DIRS})

add_test(NAME simple_test COMMAND engine_tests)
