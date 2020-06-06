include(../build/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB cpp_boilerplate_SRCS
        "*.h"
        "*.cpp"
        "features/*.cpp"
        "features/*.h"
        )
add_executable(cpp_boilerplate main.cpp ${cpp_boilerplate_SRCS})
target_link_libraries(cpp_boilerplate ${CONAN_LIBS})
