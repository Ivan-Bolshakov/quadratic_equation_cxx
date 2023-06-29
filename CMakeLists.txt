cmake_minimum_required(VERSION 3.2)

project(cmake VERSION 0.0.1)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(quadratic_equation_main src/main.cpp)

add_library(quadratic_equation src/quadratic_equation.cpp)

add_subdirectory(gtest)
include_directories(gtest/googletest/include)
include_directories(src)

add_executable(test_quadratic_equation test/quadratic_equation_test.cpp)

set_target_properties(quadratic_equation_main quadratic_equation test_quadratic_equation PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(test_quadratic_equation PRIVATE gtest quadratic_equation)

target_link_libraries(quadratic_equation_main quadratic_equation)

install(TARGETS quadratic_equation_main RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(test_quadratic_equation_tests test_quadratic_equation)
