# 'Google_test' is the subproject name
project(CPLUS-UnitTest-googletest-main/build)

# 'lib' is the folder with Google Test sources
add_subdirectory(CPLUS-UnitTest-googletest-main/build/lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(CPLUS-UnitTest-googletest-main/build test.cpp)
target_link_libraries(CPLUS-UnitTest-googletest-main/build gtest gtest_main)