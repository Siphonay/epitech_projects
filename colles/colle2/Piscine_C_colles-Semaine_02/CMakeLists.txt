cmake_minimum_required(VERSION 3.3)
project(Piscine_C_colles_Semaine_02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.c
    my_getnbr.c
    my_putchar.c
    my_putstr.c
    my_strlen.c)

add_executable(Piscine_C_colles_Semaine_02 ${SOURCE_FILES})