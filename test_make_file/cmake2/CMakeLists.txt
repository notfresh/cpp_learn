cmake_minimum_required(VERSION 2.8)

project(main)

aux_source_directory(. dir1)

add_executable(main ${dir1})
