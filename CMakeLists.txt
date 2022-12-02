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

set(BUILD_6 10.cpp)
set(SOURCE_FILES_6 "Task 10/10.cpp")
add_executable(${BUILD_6} ${SOURCE_FILES_6})

set(BUILD_7 11.1.cpp)
set(COMMON_SOURCES "Task 11/Point.cpp")
set(TARGET_SOURCES "Task 11/11.1.cpp")
add_executable(${BUILD_7} ${COMMON_SOURCES} ${TARGET_SOURCES})

set(BUILD_8 11.2.cpp)
set(SOURCE_FILES_8 "Task 11/Point.h" "Task 11/Point.cpp" "Task 11/11.2.cpp" "Task 11/Triangle.h" "Task 11/Triangle.cpp")
add_executable(${BUILD_8} ${SOURCE_FILES_8} "Task 11/Triangle.h" "Task 11/Triangle.cpp")

set(BUILD_9 Point.cpp)
set(SOURCE_FILES_9 "Task 11/Point.cpp")
add_executable(${BUILD_9} ${SOURCE_FILES_9})

set(BUILD_10 2.0.1.cpp)
set(SOURCE_FILES_10 "Task 2/2.0.1.cpp")
add_executable(${BUILD_10} ${SOURCE_FILES_10})

set(BUILD_11 2.0.2.cpp)
set(SOURCE_FILES_11 "Task 2/2.0.2.cpp")
add_executable(${BUILD_11} ${SOURCE_FILES_11})

set(BUILD_12 2.1.cpp)
set(SOURCE_FILES_12 "Task 2/2.1.cpp")
add_executable(${BUILD_12} ${SOURCE_FILES_12})

set(BUILD_13 2.2.cpp)
set(SOURCE_FILES_13 "Task 2/2.2.cpp")
add_executable(${BUILD_13} ${SOURCE_FILES_13})

set(BUILD_14 3.cpp)
set(SOURCE_FILES_14 "Task 3/3.cpp")
add_executable(${BUILD_14} ${SOURCE_FILES_14})

set(BUILD_15 4.1.cpp)
set(SOURCE_FILES_15 "Task 4/4.1.cpp")
add_executable(${BUILD_15} ${SOURCE_FILES_15})

set(BUILD_16 4.2.cpp)
set(SOURCE_FILES_16 "Task 4/4.2.cpp")
add_executable(${BUILD_16} ${SOURCE_FILES_16})

set(BUILD_17 5.1.cpp)
set(SOURCE_FILES_17 "Task 5/5.1.cpp")
add_executable(${BUILD_17} ${SOURCE_FILES_17})

set(BUILD_18 5.2.1.cpp)
set(SOURCE_FILES_18 "Task 5/5.2.1.cpp")
add_executable(${BUILD_18} ${SOURCE_FILES_18})

set(BUILD_19 6.1.cpp)
set(SOURCE_FILES_19 "Task 6/6.1.cpp")
add_executable(${BUILD_19} ${SOURCE_FILES_19})

set(BUILD_20 6.cpp)
set(SOURCE_FILES_20 "Task 6/6.cpp")
add_executable(${BUILD_20} ${SOURCE_FILES_20})

set(BUILD_21 7.cpp)
set(SOURCE_FILES_21 "Task 7/7.cpp")
add_executable(${BUILD_21} ${SOURCE_FILES_21})

set(BUILD_22 8.1.cpp)
set(SOURCE_FILES_22 "Task 8/8.1.cpp")
add_executable(${BUILD_22} ${SOURCE_FILES_22})

set(BUILD_23 8.2.cpp)
set(SOURCE_FILES_23 "Task 8/8.2.cpp")
add_executable(${BUILD_23} ${SOURCE_FILES_23})

set(BUILD_24 9.cpp)
set(SOURCE_FILES_24 "Task 9/9.cpp")
add_executable(${BUILD_24} ${SOURCE_FILES_24})
