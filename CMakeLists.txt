cmake_minimum_required(VERSION 3.22)
project(mastering_c)
add_executable(main /home/shankar/Shiva/cs1010/Lecture-Notes/permutation.c)
add_compile_options(-Wall -Wextra -Wpedantic -g)

# static library
set(libs_static "/home/shankar/Shiva/cs1010/lib/libcs1010.a")

target_include_directories(main PUBLIC
    "/home/shankar/Shiva/cs1010/include"
)

# find_library(FOO_LIB libcs1010)

# It is recommended that you always compile with -g flags during the development phase. If you need to measure the performance (e.g., how fast it runs) of your program or when you are releasing the program to the public, you can remove the -g flag and compile with the optimization flags (e.g., -O) instead.

# This is for math.h tool: "-l m" which calling "libm.so"
target_link_libraries(main PUBLIC ${libs_static} ${libs_shared} m)
