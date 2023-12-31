cmake_minimum_required(VERSION 3.22)
project(mastering_c)
add_executable(main /home/shankar/Shiva/cs1010/Practice-Exercises-AY1718/Practice-S01P01/skeleton/freezer.c)

add_compile_options(-Wall -Wextra -Wpedantic -g)

# It is recommended that you always compile with -g flags during the development phase. If you need to measure the performance (e.g., how fast it runs) of your program or when you are releasing the program to the public, you can remove the -g flag and compile with the optimization flags (e.g., -O) instead.

# This is for math.h tool: "-l m" which calling "libm.so"
target_link_libraries(main ${libs_static} ${libs_shared} m)
