cmake_minimum_required(VERSION 3.7)
project(ProgC C)

set(CMAKE_C_STANDARD 99)

add_executable(ProgC main.c Author.c Author.h ListGenre.c ListGenre.h Book.c Book.h Mediatheque.c Mediatheque.h)