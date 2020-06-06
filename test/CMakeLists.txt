cmake_minimum_required(VERSION 3.16)
project(Test)
include(CTest)
enable_testing()
include_directories(${CPP_BOILERPLATE_SOURCE_DIR}/src)
#set(gtest_disable_pthreads on) #needed in MinGW
include(../build/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB test_SRC
        "*.h"
        "*.cpp"
        "../src/features/*.cpp"
        "../src/features/*.h"
        )
add_executable(runUnitTests gtest.cpp ${test_SRC})
target_link_libraries(runUnitTests gtest gmock)
#add_test(runUnitTests runUnitTests) #included in all tutorials but I don't know what it actually does