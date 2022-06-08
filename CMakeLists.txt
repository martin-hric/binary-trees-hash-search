cmake_minimum_required(VERSION 3.17)
project(zadanie2 C)

set(CMAKE_C_STANDARD 99)

add_executable(zadanie2 my_avl.c my_avl.h main.c R&B_from_net.c R&B_from_net.h hash_chaining.c hash_chaining.h)