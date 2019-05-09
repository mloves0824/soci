cmake_minimum_required(VERSION 3.0.0)
project(soci_test VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories("/usr/include/mysql")
add_executable(soci_test main.cpp db_manager.cpp)
link_directories("/usr/local/lib64")
target_link_libraries(soci_test soci_core)
target_link_libraries(soci_test soci_mysql)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)