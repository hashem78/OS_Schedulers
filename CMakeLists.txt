# CMakeList.txt : CMake project for OS_Schedulers, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)


project ("OS_Schedulers")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add source to this project's executable.
add_executable (OS_Schedulers "OS_Schedulers.cpp" "OS_Schedulers.h" "include/process.h" "lib/process.cpp" "include/schedulers/scheduler.h"  "include/schedulers/fifo.h" "lib/schedulers/scheduler.cpp" "lib/schedulers/fifo.cpp" "include/schedulers/sjf.h" "lib/schedulers/sjf.cpp" "include/schedulers/srt.h" "lib/schedulers/srt.cpp" "include/schedulers/rr.h" "lib/schedulers/rr.cpp")

# TODO: Add tests and install targets if needed.
