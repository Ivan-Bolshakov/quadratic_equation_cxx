cmake_minimum_required(VERSION 3.2)

project(cmake VERSION 0.0.1)

configure_file(src/version.h.in ${PROJECT_SOURCE_DIR}/src/version.h)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(helloworld_cli src/main.cpp)

add_library(helloworld src/lib.cpp)

add_subdirectory(gtest)
include_directories(gtest/googletest/include)
include_directories(src)

add_executable(test_version test/quadratic_equation_test.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(test_version PRIVATE gtest helloworld)

target_link_libraries(helloworld_cli helloworld)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(helloworld_tests test_version)
