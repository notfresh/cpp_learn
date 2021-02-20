cmake_minimum_required(VERSION 2.8)


project(main)

add_executable(main main.cpp a.cpp b.cpp)

find_package(fmt)
target_link_libraries(main fmt::fmt)
