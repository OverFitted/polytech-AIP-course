cmake_minimum_required(VERSION 3.3)
project(Polytech_AIP)

set(CMAKE_CXX_STANDARD 14)


set(BUILD_1 1.0.1.cpp)
set(SOURCE_FILES_1 "Task 1/1.0.1.cpp")
add_executable(${BUILD_1} ${SOURCE_FILES_1})

set(BUILD_2 1.0.2.cpp)
set(SOURCE_FILES_2 "Task 1/1.0.2.cpp")
add_executable(${BUILD_2} ${SOURCE_FILES_2})

set(BUILD_3 1.1.cpp)
set(SOURCE_FILES_3 "Task 1/1.1.cpp")
add_executable(${BUILD_3} ${SOURCE_FILES_3})

set(BUILD_4 1.2.cpp)
set(SOURCE_FILES_4 "Task 1/1.2.cpp")
add_executable(${BUILD_4} ${SOURCE_FILES_4})

set(BUILD_5 1.3.cpp)
set(SOURCE_FILES_5 "Task 1/1.3.cpp")
add_executable(${BUILD_5} ${SOURCE_FILES_5})

set(BUILD_6 2.0.1.cpp)
set(SOURCE_FILES_6 "Task 2/2.0.1.cpp")
add_executable(${BUILD_6} ${SOURCE_FILES_6})

set(BUILD_7 2.0.2.cpp)
set(SOURCE_FILES_7 "Task 2/2.0.2.cpp")
add_executable(${BUILD_7} ${SOURCE_FILES_7})

set(BUILD_8 2.1.cpp)
set(SOURCE_FILES_8 "Task 2/2.1.cpp")
add_executable(${BUILD_8} ${SOURCE_FILES_8})

set(BUILD_9 2.2.cpp)
set(SOURCE_FILES_9 "Task 2/2.2.cpp")
add_executable(${BUILD_9} ${SOURCE_FILES_9})

set(BUILD_10 3.cpp)
set(SOURCE_FILES_10 "Task 3/3.cpp")
add_executable(${BUILD_10} ${SOURCE_FILES_10})
