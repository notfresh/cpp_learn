cmake_minimum_required(VERSION 3.15)
project(cpp_learn)

add_executable(singleton-multithread designPattern/singleton-multithread.cpp)
add_executable(test_virtual test_oop/test_virtual.cpp)
add_executable(test_delete_deconstructor test_oop/test_delete_deconstructor.cpp)
add_executable(singleton-multithread-template designPattern/singleton-multithread-template.cpp)
add_executable(singleton-multithread-template-fault designPattern/singleton-multithread-template-static-local.cpp)
add_executable(singleton-multithread-template2 designPattern/singleton-multithread-template2.cpp)