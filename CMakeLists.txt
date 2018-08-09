cmake_minimum_required(VERSION 3.7)
set (CMAKE_CXX_STANDARD 14)
project(gmock_example)

set (GCC_COVERAGE_COMPILE_FLAGS "-coverage -fprofile-arcs -ftest-coverage")
set (GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set (CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

file(GLOB_RECURSE sources "src/*.cpp" "src/*.cc")
set(testing_sources ${sources})
list(FILTER sources EXCLUDE REGEX ".(/tests/).")

include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/inc)

add_executable(gme ${sources})
add_executable(test_gme ${testing_sources})

target_compile_definitions(test_gme PUBLIC -DTEST)


target_link_libraries(test_gme ${GTEST_BOTH_LIBRARIES}
                               ${GMOCK_BOTH_LIBRARIES})

